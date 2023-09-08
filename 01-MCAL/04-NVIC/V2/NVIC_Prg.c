/**
*@file       NVIC_Prg.c
*@version    1.0.0
*@brief      MCAL Nested vectored interrupt controller .
*@details    It contains the core driver
*@author     Shehab aldeen mohammed abdalah
*/

#include "NVIC_Interface.h"
#include "NVIC_Private.h"

/* To define global array of pointer to functions that execute in ISR */
typedef void (*FunctionPtr)(void);
FunctionPtr functionArray[67];

/* Enable an interrupt */
void MNVIC_EnableIRQ(IRQn_Type IRQn  ){
	if (  (IRQn >= NVIC_WWDG && IRQn <= NVIC_OTG_FS_WKUP ) || (IRQn >= NVIC_TIM5 && IRQn <= NVIC_OTG_FS)){
		NVIC->ISER[IRQn/REG_SIZE] = (STD_ON<<IRQn%REG_SIZE) ;
	}
	else {
		Det_ReportError(MODULE_ID,MNVIC_EnableIRQ_ID , NVIC_E_PARAM_INVALID_ARGUMENT);
	}
}

uint8 MNVIC_GetStateEnableIRQ(IRQn_Type IRQn  ){
	if (  (IRQn >= NVIC_WWDG && IRQn <= NVIC_OTG_FS_WKUP) || (IRQn >= NVIC_TIM5 && IRQn <= NVIC_OTG_FS)){
		return GET_BIT(NVIC->ISER[IRQn/REG_SIZE],IRQn%REG_SIZE);
	}
	else {
		Det_ReportError(MODULE_ID,MNVIC_GetStateEnableIRQ_ID , NVIC_E_PARAM_INVALID_ARGUMENT);
	}
	return 0 ;
}

/* Disable an interrupt */
void MNVIC_DisableIRQ(IRQn_Type IRQn){
	if (  (IRQn >= NVIC_WWDG && IRQn <= NVIC_OTG_FS_WKUP) || (IRQn >= NVIC_TIM5 && IRQn <= NVIC_OTG_FS)){
		NVIC->ICER[IRQn/REG_SIZE] = (STD_ON<<IRQn%REG_SIZE) ;
	}
	else {
		Det_ReportError(MODULE_ID,MNVIC_DisableIRQ_ID , NVIC_E_PARAM_INVALID_ARGUMENT);
	}
}

/* enable pending an interrupt */
void MNVIC_PendingEnableIRQ(IRQn_Type IRQn){
	if (  (IRQn >= NVIC_WWDG && IRQn <= NVIC_OTG_FS_WKUP) || (IRQn >= NVIC_TIM5 && IRQn <= NVIC_OTG_FS)){
		NVIC->ISPR[IRQn/REG_SIZE] = (STD_ON<<IRQn%REG_SIZE) ;
	}
	else {
		Det_ReportError(MODULE_ID , MNVIC_PendingEnableIRQ_ID , NVIC_E_PARAM_INVALID_ARGUMENT);
	}
}

uint8 MNVIC_GetStatePendingIRQ(IRQn_Type IRQn){
	if (  (IRQn >= NVIC_WWDG && IRQn <= NVIC_OTG_FS_WKUP) || (IRQn >= NVIC_TIM5 && IRQn <= NVIC_OTG_FS)){
		return GET_BIT(NVIC->ISPR[IRQn/REG_SIZE],IRQn%REG_SIZE);
	}
	else {
		Det_ReportError(MODULE_ID,MNVIC_GetStatePendingIRQ_ID , NVIC_E_PARAM_INVALID_ARGUMENT);
	}
	return 0 ;
}

/* disable pending an interrupt */
void MNVIC_PendingDisableIRQ(IRQn_Type IRQn){
	if (  (IRQn >= NVIC_WWDG && IRQn <= NVIC_OTG_FS_WKUP) || (IRQn >= NVIC_TIM5 && IRQn <= NVIC_OTG_FS)){
		NVIC->ICPR[IRQn/REG_SIZE] = (STD_ON<<IRQn%REG_SIZE) ;
	}
	else {
		Det_ReportError(MODULE_ID,MNVIC_PendingDisableIRQ_ID , NVIC_E_PARAM_INVALID_ARGUMENT);
	}
}

/*to set call back function*/
void MNVIC_SetCallBackFunc (uint8 INT_Position,void (*Copy_ptr)(void)){
	if (  Copy_ptr == NULL_PTR ){
		Det_ReportError(MODULE_ID, MNVIC_SetCallBackFunc_ID, NVIC_E_PARAM_POINTER);
	}
	else {
		functionArray[INT_Position] = Copy_ptr ;
	}
}

/* to determine active flag state of interrupt */
uint8 MNVIC_GetActive(IRQn_Type IRQn){
	if (  (IRQn >= NVIC_WWDG && IRQn <= NVIC_OTG_FS_WKUP) || (IRQn >= NVIC_TIM5 && IRQn <= NVIC_OTG_FS)){
		return GET_BIT(NVIC->IABR[IRQn/REG_SIZE],IRQn%REG_SIZE);
	}
	else {
		Det_ReportError(MODULE_ID , MNVIC_GetActive_ID , NVIC_E_PARAM_INVALID_ARGUMENT);
	}
	return 0;
}


/* Set the priority of an interrupt */
void MNVIC_SetPriority(IRQn_Type IRQn, uint8 priority){
	if (  (IRQn >= NVIC_WWDG && IRQn <= NVIC_OTG_FS_WKUP) || (IRQn >= NVIC_TIM5 && IRQn <= NVIC_OTG_FS)){
		NVIC->IP[IRQn] = (priority << HALF_BYTE) ;
	}
	else {
		Det_ReportError(MODULE_ID , MNVIC_SetPriority_ID , NVIC_E_PARAM_INVALID_ARGUMENT);
	}
}

/*to set the number of groups*/
void MNVIC_SetPriorityGroup (uint32 NumOfGroups){
	/*
	PRIGROUP    Binary        Group priority          Subpriority    Group            Sub
	 [2:0]      point         bits                    bits          priorities       priorities
	0b011      0bxxxx          [7:4]                    None           16               None
	0b100      0bxxx.y         [7:5]                    [4]            8                 2
	0b101      0bxx.yy         [7:6]                    [5:4]          4                 4
	0b110      0bx.yyy         [7]                      [6:4]          2                 8
	0b111      0b.yyyy         None                     [7:4]         None               16
	  */
	if ( NumOfGroups >= SIXTEEN_GROUPS_ZERO_SUB && NumOfGroups <= ZERO_GROUPS_SIXTEEN_SUB ){
		SCB_AIRCR    = NumOfGroups ;
	}
	else {
		Det_ReportError(MODULE_ID , MNVIC_SetPriorityGroup_ID , NVIC_E_PARAM_INVALID_ARGUMENT);
	}
}


/* Get the priority of an interrupt */
uint8  MNVIC_GetPriority(IRQn_Type IRQn){
	if (  (IRQn >= NVIC_WWDG && IRQn <= NVIC_OTG_FS_WKUP) || (IRQn >= NVIC_TIM5 && IRQn <= NVIC_OTG_FS)){
		return NVIC->IP[IRQn]; /*Read The Priority of the IRQ*/
	}
	else {
		Det_ReportError(MODULE_ID , MNVIC_GetPriority_ID , NVIC_E_PARAM_INVALID_ARGUMENT);
	}
	return 0 ;
}

/* to get info of diver */
void  NVIC_GetVersionInfo(Std_VersionInfoType* versioninfo){
	versioninfo->moduleID         = MODULE_ID         ;
	versioninfo->sw_major_version = NVIC_MAJOR_VERSION ;
	versioninfo->sw_minor_version = NVIC_MINOR_VERSION ;
	versioninfo->sw_patch_version = NVIC_PATCH_VERSION ;
	versioninfo->vendorID         = VENDOR_ID         ;
}

void WWDG_IRQHandler(void) {
    if (functionArray[NVIC_WWDG] != NULL_PTR) {
    	functionArray[NVIC_WWDG]();
    }
    else {
        Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void PVD_IRQHandler(void) {
    if (functionArray[NVIC_PVD] != NULL_PTR) {
    	functionArray[NVIC_PVD]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void TAMPER_IRQHandler(void) {
    if (functionArray[NVIC_TAMPER] != NULL_PTR) {
    	functionArray[NVIC_TAMPER]();
    } else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void RTC_IRQHandler(void) {
    if (functionArray[NVIC_RTC] != NULL_PTR) {
    	functionArray[NVIC_RTC]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void FLASH_IRQHandler(void) {
    if (functionArray[NVIC_FLASH] != NULL_PTR) {
    	functionArray[NVIC_FLASH]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}


void RCC_IRQHandler(void) {
    if (functionArray[NVIC_RCC] != NULL_PTR) {
    	functionArray[NVIC_RCC]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void EXTI0_IRQHandler(void) {
    if (functionArray[NVIC_EXTI0] != NULL_PTR) {
    	functionArray[NVIC_EXTI0]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void EXTI1_IRQHandler(void) {
    if (functionArray[NVIC_EXTI1] != NULL_PTR) {
    	functionArray[NVIC_EXTI1]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void EXTI2_IRQHandler(void) {
    if (functionArray[NVIC_EXTI2] != NULL_PTR) {
    	functionArray[NVIC_EXTI2]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void EXTI3_IRQHandler(void) {
    if (functionArray[NVIC_EXTI3] != NULL_PTR) {
    	functionArray[NVIC_EXTI3]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void EXTI4_IRQHandler(void) {
    if (functionArray[NVIC_EXTI4] != NULL_PTR) {
    	functionArray[NVIC_EXTI4]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void DMA1_Channel1_IRQHandler(void) {
    if (functionArray[NVIC_DMA1_Channel1] != NULL_PTR) {
    	functionArray[NVIC_DMA1_Channel1]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void DMA1_Channel2_IRQHandler(void) {
    if (functionArray[NVIC_DMA1_Channel2] != NULL_PTR) {
    	functionArray[NVIC_DMA1_Channel2]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void DMA1_Channel3_IRQHandler(void) {
    if (functionArray[NVIC_DMA1_Channel3] != NULL_PTR) {
    	functionArray[NVIC_DMA1_Channel3]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void DMA1_Channel4_IRQHandler(void) {
    if (functionArray[NVIC_DMA1_Channel4] != NULL_PTR) {
    	functionArray[NVIC_DMA1_Channel4]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void DMA1_Channel5_IRQHandler(void) {
    if (functionArray[NVIC_DMA1_Channel5] != NULL_PTR) {
    	functionArray[NVIC_DMA1_Channel5]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void DMA1_Channel6_IRQHandler(void) {
    if (functionArray[NVIC_DMA1_Channel6] != NULL_PTR) {
    	functionArray[NVIC_DMA1_Channel6]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void DMA1_Channel7_IRQHandler(void) {
    if (functionArray[NVIC_DMA1_Channel7] != NULL_PTR) {
    	functionArray[NVIC_DMA1_Channel7]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void ADC1_2_IRQHandler(void) {
    if (functionArray[NVIC_ADC1_2] != NULL_PTR) {
    	functionArray[NVIC_ADC1_2]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void CAN1_TX_IRQHandler(void) {
    if (functionArray[NVIC_CAN1_TX] != NULL_PTR) {
    	functionArray[NVIC_CAN1_TX]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void CAN1_RX0_IRQHandler(void) {
    if (functionArray[NVIC_CAN1_RX0] != NULL_PTR) {
    	functionArray[NVIC_CAN1_RX0]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void CAN1_RX1_IRQHandler(void) {
    if (functionArray[NVIC_CAN1_RX1] != NULL_PTR) {
    	functionArray[NVIC_CAN1_RX1]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void CAN1_SCE_IRQHandler(void) {
    if (functionArray[NVIC_CAN1_SCE] != NULL_PTR) {
    	functionArray[NVIC_CAN1_SCE]();
    } else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void EXTI9_5_IRQHandler(void) {
    if (functionArray[NVIC_EXTI9_5] != NULL_PTR) {
    	functionArray[NVIC_EXTI9_5]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void TIM1_BRK_IRQHandler(void) {
    if (functionArray[NVIC_TIM1_BRK] != NULL_PTR) {
    	functionArray[NVIC_TIM1_BRK]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void TIM1_UP_IRQHandler(void) {
    if (functionArray[NVIC_TIM1_UP] != NULL_PTR) {
    	functionArray[NVIC_TIM1_UP]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void TIM1_TRG_COM_IRQHandler(void) {
    if (functionArray[NVIC_TIM1_TRG_COM] != NULL_PTR) {
    	functionArray[NVIC_TIM1_TRG_COM]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void TIM1_CC_IRQHandler(void) {
    if (functionArray[NVIC_TIM1_CC] != NULL_PTR) {
    	functionArray[NVIC_TIM1_CC]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void TIM2_IRQHandler(void) {
    if (functionArray[NVIC_TIM2] != NULL_PTR) {
    	functionArray[NVIC_TIM2]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void TIM3_IRQHandler(void) {
    if (functionArray[NVIC_TIM3] != NULL_PTR) {
    	functionArray[NVIC_TIM3]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void TIM4_IRQHandler(void) {
    if (functionArray[NVIC_TIM4] != NULL_PTR) {
    	functionArray[NVIC_TIM4]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void I2C1_EV_IRQHandler(void) {
    if (functionArray[NVIC_I2C1_EV] != NULL_PTR) {
    	functionArray[NVIC_I2C1_EV]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void I2C1_ER_IRQHandler(void) {
    if (functionArray[NVIC_I2C1_ER] != NULL_PTR) {
    	functionArray[NVIC_I2C1_ER]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void I2C2_EV_IRQHandler(void) {
    if (functionArray[NVIC_I2C2_EV] != NULL_PTR) {
    	functionArray[NVIC_I2C2_EV]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void I2C2_ER_IRQHandler(void) {
    if (functionArray[NVIC_I2C2_ER] != NULL_PTR) {
    	functionArray[NVIC_I2C2_ER]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void SPI1_IRQHandler(void) {
    if (functionArray[NVIC_SPI1] != NULL_PTR) {
    	functionArray[NVIC_SPI1]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void SPI2_IRQHandler(void) {
    if (functionArray[NVIC_SPI2] != NULL_PTR) {
    	functionArray[NVIC_SPI2]();
    } else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void USART1_IRQHandler(void) {
    if (functionArray[NVIC_USART1] != NULL_PTR) {
    	functionArray[NVIC_USART1]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void USART2_IRQHandler(void) {
    if (functionArray[NVIC_USART2] != NULL_PTR) {
    	functionArray[NVIC_USART2]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void USART3_IRQHandler(void) {
    if (functionArray[NVIC_USART3] != NULL_PTR) {
    	functionArray[NVIC_USART3]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void EXTI15_10_IRQHandler(void) {
    if (functionArray[NVIC_EXTI15_10] != NULL_PTR) {
    	functionArray[NVIC_EXTI15_10]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void RTCAlarm_IRQHandler(void) {
    if (functionArray[NVIC_RTCAlarm] != NULL_PTR) {
    	functionArray[NVIC_RTCAlarm]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

void OTG_FS_WKUP_IRQHandler(void) {
    if (functionArray[NVIC_OTG_FS] != NULL_PTR) {
    	functionArray[NVIC_OTG_FS]();
    }
    else {
    	Det_ReportError(MODULE_ID, MNVIC_ISR_ID, NVIC_E_PARAM_POINTER);
    }
}

