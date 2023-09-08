/**
*@file       MGPIO_Prg.c
*@version    1.0.0
*@brief      AUTOSAR Base - Platform dependend data type defination.
*@details    It has the core code of driver
*@author     Shehab aldeen mohammed abdalah
*/

/*===========================================================================
*   Project          : AUTOSAR  4.3.1 MCAL
*   Platform         : ARM
*   Peripherial      : STM32F103C8T6
*   AUTOSAR Version  : 4.3.1
*   AUTOSAR Revision : ASR_REL_4_1_REV_0001
*   SW Version       : 1.0.0
============================================================================*/


#include "DIO_Interface.h"
#include "DIO_Private.h"



/*
  Input  : Dio_ChannelType
  output : Dio_LevelType
  description :
*/
Dio_LevelType     Dio_ReadChannel (Dio_ChannelType ChannelId){
	if ( ChannelId >= Dio_A0  && ChannelId <= Dio_A15 ){
		return ( (GPIOA->IDR >> (ChannelId ) )  & STD_HIGH ) ;
	}
	else if (ChannelId >= Dio_B0  && ChannelId <= Dio_B15){
		return ( (GPIOB->IDR >> (ChannelId ) )  & STD_HIGH ) ;
	}
	else if (ChannelId == Dio_C14  || ChannelId == Dio_C15){
		return ( (GPIOC->IDR >> (ChannelId ) )  & STD_HIGH ) ;
	}
	else {
		Det_ReportError(MODULE_ID, Dio_ReadChannel_ID, DIO_E_PARAM_INVALID_CHANNEL_ID);
	}
	return STD_IDLE;
}



/*
  Input  : Dio_ChannelType
  output : Dio_LevelType
  description :
*/
void              Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level){
	if ( ChannelId >= Dio_A0  && ChannelId <= Dio_A15 ){

		if (Level == STD_HIGH){
			GPIOA->BSRR = ( 1 << ChannelId ) ;
		}
		else if (Level == STD_LOW){
			GPIOA->BRR  = ( 1 << ChannelId ) ;
		}
		else {
			Det_ReportError(MODULE_ID,  Dio_WriteChannel_ID, DIO_E_PARAM_INVALID_CHANNEL_ID);
		}
	}
	else if (ChannelId >= Dio_B0  && ChannelId <= Dio_B15){
		/*  to clear the bit that we used in define port */
		CLR_BIT(ChannelId,4);

		if (Level == STD_HIGH){
			GPIOB->BSRR = ( 1 << ChannelId ) ;
		}
		else if (Level == STD_LOW){
			GPIOB->BRR  = ( 1 << ChannelId ) ;
		}
		else {
			Det_ReportError(MODULE_ID,  Dio_WriteChannel_ID, DIO_E_PARAM_INVALID_CHANNEL_ID);
		}
	}
	else if (ChannelId == Dio_C14  || ChannelId == Dio_C15){
		/*  to clear the bit that we used in define port */
		CLR_BIT(ChannelId,5);

		if (Level == STD_HIGH){
			GPIOC->BSRR = ( 1 << ChannelId ) ;
		}
		else if (Level == STD_LOW){
			GPIOC->BRR  = ( 1 << ChannelId ) ;
		}
		else {
			Det_ReportError(MODULE_ID,  Dio_WriteChannel_ID, DIO_E_PARAM_INVALID_CHANNEL_ID);
		}
	}
	else {
		Det_ReportError(MODULE_ID,  Dio_WriteChannel_ID, DIO_E_PARAM_INVALID_CHANNEL_ID);
	}
}



/*
  Input  : Dio_PortType
  output : Dio_LevelType
  description :
*/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId){
	switch (PortId){
	case Dio_GPIO_A :
		return GPIOA->IDR;
	case Dio_GPIO_B :
		return GPIOB->IDR;
	case Dio_GPIO_C :
		return GPIOC->IDR;
	default :
		Det_ReportError(MODULE_ID,  Dio_ReadPort_ID, DIO_E_PARAM_INVALID_PORT_ID);
	}
	return STD_IDLE;
}


/*
  Input  : Dio_PortType , Dio_PortLevelType
  output : None
  description :
*/
void              Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level){
	switch (PortId){
	case Dio_GPIO_A :
		GPIOA->ODR = Level ;
		break ;
	case Dio_GPIO_B :
		GPIOA->ODR = Level ;
		break ;
	case Dio_GPIO_C :
		GPIOA->ODR = Level ;
		break ;
	default :
		Det_ReportError(MODULE_ID,   Dio_WritePort_ID, DIO_E_PARAM_INVALID_PORT_ID);
	}
}


/*
  Input  : Std_VersionInfoType
  output : None
  description :
*/
void              Dio_GetVersionInfo(Std_VersionInfoType* versioninfo){
	versioninfo->moduleID         = MODULE_ID         ;
	versioninfo->sw_major_version = PORT_MAJOR_VERSION ;
	versioninfo->sw_minor_version = PORT_MINOR_VERSION ;
	versioninfo->sw_patch_version = PORT_PATCH_VERSION ;
	versioninfo->vendorID         = VENDOR_ID         ;
}


/*
  Input  : Dio_ChannelType
  output : Dio_LevelType
  description :
*/
Dio_LevelType     Dio_FlipChannel(Dio_ChannelType ChannelId){
	if ( ChannelId >= Dio_A0  && ChannelId <= Dio_A15 ){
		TOGGLE_BIT(GPIOA->ODR,ChannelId);
	}
	else if (ChannelId >= Dio_B0  && ChannelId <= Dio_B15){
		/*  to clear the bit that we used in define port */
		CLR_BIT(ChannelId,5);

		TOGGLE_BIT(GPIOB->ODR,ChannelId);
	}
	else if (ChannelId >= Dio_C14  || ChannelId <= Dio_C15){
		/*  to clear the bit that we used in define port */
		CLR_BIT(ChannelId,5);

		TOGGLE_BIT(GPIOC->ODR,ChannelId);
	}
	else {
		Det_ReportError(MODULE_ID,   Dio_FlipChannel_ID, DIO_E_PARAM_INVALID_CHANNEL_ID);
	}
	return STD_IDLE;
}






