/**
*@file       MCU_Prg.c
*@version    1.0.0
*@brief      AUTOSAR Base - Platform dependend data type defination.
*@details    It has the core code of driver
*@author     Shehab aldeen mohammed abdalah
*/

/*===========================================================================
*   Project          : AUTOSAR  4.3.1 MCAL
*   Platform         : ARM
*   Peripherial      : STM32F103C8T6
*   AUTOSAR Version  : R20-11
*   AUTOSAR Revision : ASR_REL_4_1_REV_0001
*   SW Version       : 1.0.0
============================================================================*/

/****************************************************************************
*****************************  Includes   ***********************************
*****************************************************************************/
#include "MCU_Interface.h"
#include "MCU_Private.h"

void   Mcu_Init (const Mcu_ConfigType* ConfigPtr) {
	/* check on coming pointer */
	if (NULL_PTR == ConfigPtr){
		Det_ReportError(MODULE_ID, Mcu_Init_ID, MCU_E_PARAM_POINTER);
	}

	/* to select HSE[16] */
	RCC->CR      = ConfigPtr->CLOCK_SYS | ( ConfigPtr->HSITRIM << 3 ) ;

	/* to check that the clock is stabled  :
	 PLLRDY    or   HSERDY   or   HSIRDY
	 */
	uint32 LOCAL_Clock_Flag = ( ConfigPtr->CLOCK_SYS << 1 ) ;  /*  to check on one in the bit of flag  */
	uint16 LOCAL_Time_limit = 1000 ;
	while ( (LOCAL_Clock_Flag & RCC->CR) && (0 == LOCAL_Time_limit))
	{
		LOCAL_Time_limit--;
	}
	if (0 == LOCAL_Time_limit){
		Det_ReportError(MODULE_ID, Mcu_Init_ID, MCU_E_TIMEOUT);
	}

	/* to turn off VCC in PIN out that used in HSE to get clock */
#if   HSE == HSE_CRSTYAL
	CLR_BIT(RCC->CR,HSE_BYP);
#elif HSE == HSE_RC
	SET_BIT(RCC->CR,HSE_BYP);
#endif

#if CSS_CFG == CSS_OFF
	CLR_BIT(RCC->CR,CSSON);
#elif CSS_CFG == CSS_ON
	SET_BIT(RCC->CR,CSSON);
#endif

	/* to select SW[1:0]
	 00: HSI selected as system clock
	 01: HSE selected as system clock
     10: PLL selected as system clock
	  */
	RCC->CFGR    = ConfigPtr->PLL_MUL_NUMBER | ConfigPtr->PLL_ENTRY_CLOCK | ConfigPtr->ADC_PRESCALAR_
			       | ConfigPtr->APB2_PRESCALAR_ | ConfigPtr->APB1_PRESCALAR_ | ConfigPtr->AHB_PRESCALAR_
				   | ConfigPtr->SW_ENABLE_CLOCK  ;

}


void Mcu_SetMode (Mcu_ModeType McuMode){
	if ( McuMode >= APB1_PER_TIM2  && McuMode <= APB1_PER_DAC ){
		RCC->APB1ENR  |= McuMode ;
	}
	else if (McuMode >= APB2_PER_AFIO  && McuMode <= APB2_PER_TIM11){
		CLR_BIT(McuMode,31);
		RCC->APB2ENR  |= McuMode ;
	}
	else if (McuMode >= AHB_PER_DMA_1  && McuMode <= AHB_PER_SDIO){
		CLR_BIT(McuMode,30);
		RCC->AHBENR  |= McuMode ;
	}
	else {
		Det_ReportError(MODULE_ID, Mcu_SetMode_ID, MCU_E_PARAM_MODE);
	}
}


void Mcu_GetVersionInfo(Std_VersionInfoType* versioninfo) {
	versioninfo->moduleID         = MODULE_ID         ;
	versioninfo->sw_major_version = MCU_MAJOR_VERSION ;
	versioninfo->sw_minor_version = MCU_MINOR_VERSION ;
	versioninfo->sw_patch_version = MCU_PATCH_VERSION ;
	versioninfo->vendorID         = VENDOR_ID         ;
}
