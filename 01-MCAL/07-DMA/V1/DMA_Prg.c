/*
*@file       DMA_Prg.c
*@version    1.0.0
*@brief      MCAL Direct meomry access
*@details    It contains the core driver
*@author     Shehab aldeen mohammed abdalah
*/


/**
* \file DMA_Prg.c
*
* \section Brief
*  The implementation of functions
*
* \section Scoop
*  Private
*
* \section Author
*  Shehab aldeen mohammed abdalah
*
*/

#include "DMA_Interface.h"
#include "DMA_Private.h"

/* DMA Initialization with default configurations */
void DMA_Config(const Configuration_DMA *Config_Ptr){
	switch (Config_Ptr->Copy_Channel) {
	case DMA_CH1:
		DMA_CH1_BASE->CCR = Config_Ptr->CircularMode | Config_Ptr->Priority
				| Config_Ptr->TransferType | Config_Ptr->INT_Enable
				| Config_Ptr->mIncrement | Config_Ptr->pIncrement;
		break;
	case DMA_CH2:
		DMA_CH2_BASE->CCR = Config_Ptr->CircularMode | Config_Ptr->Priority
				| Config_Ptr->TransferType | Config_Ptr->mIncrement
				| Config_Ptr->pIncrement | Config_Ptr->INT_Enable;
		break;
	case DMA_CH3:
		DMA_CH3_BASE->CCR = Config_Ptr->CircularMode | Config_Ptr->Priority
				| Config_Ptr->TransferType | Config_Ptr->mIncrement
				| Config_Ptr->pIncrement | Config_Ptr->INT_Enable;
		break;
	case DMA_CH4:
		DMA_CH4_BASE->CCR = Config_Ptr->CircularMode | Config_Ptr->Priority
				| Config_Ptr->TransferType | Config_Ptr->mIncrement
				| Config_Ptr->pIncrement | Config_Ptr->INT_Enable;
		break;
	case DMA_CH5:
		DMA_CH5_BASE->CCR = Config_Ptr->CircularMode | Config_Ptr->Priority
				| Config_Ptr->TransferType | Config_Ptr->mIncrement
				| Config_Ptr->pIncrement | Config_Ptr->INT_Enable;
		break;
	case DMA_CH6:
		DMA_CH6_BASE->CCR = Config_Ptr->CircularMode | Config_Ptr->Priority
				| Config_Ptr->TransferType | Config_Ptr->mIncrement
				| Config_Ptr->pIncrement | Config_Ptr->INT_Enable;
		break;
	case DMA_CH7:
		DMA_CH7_BASE->CCR = Config_Ptr->CircularMode | Config_Ptr->Priority
				| Config_Ptr->TransferType | Config_Ptr->mIncrement
				| Config_Ptr->pIncrement | Config_Ptr->INT_Enable;
		break;
	default:
		/* invalid parameter */
	}
}

/* DMA channel Enable*/
void DMA_ChannelEnable(Channel_DMA Copy_Channel){
	switch (Copy_Channel){
	case DMA_CH1 :
		DMA_CH1_BASE->CCR  |= 0x00000001 ;
		break ;
	case DMA_CH2 :
		DMA_CH2_BASE->CCR  |= 0x00000001 ;
		break ;
	case DMA_CH3 :
		DMA_CH3_BASE->CCR  |= 0x00000001 ;
		break ;
	case DMA_CH4 :
		DMA_CH4_BASE->CCR  |= 0x00000001 ;
		break ;
	case DMA_CH5 :
		DMA_CH5_BASE->CCR  |= 0x00000001 ;
		break ;
	case DMA_CH6 :
		DMA_CH6_BASE->CCR  |= 0x00000001 ;
		break ;
	case DMA_CH7 :
		DMA_CH7_BASE->CCR  |= 0x00000001 ;
		break ;
	default :
		/* invalid parameter */
	}
}

/* DMA channel disable */
void DMA_ChannelDisable(Channel_DMA Copy_Channel){
	switch (Copy_Channel){
	case DMA_CH1 :
		CLR_BIT(DMA_CH1_BASE->CCR ,0) ;
		break ;
	case DMA_CH2 :
		CLR_BIT(DMA_CH2_BASE->CCR ,0) ;
		break ;
	case DMA_CH3 :
		CLR_BIT(DMA_CH3_BASE->CCR ,0) ;
		break ;
	case DMA_CH4 :
		CLR_BIT(DMA_CH4_BASE->CCR ,0) ;
		break ;
	case DMA_CH5 :
		CLR_BIT(DMA_CH5_BASE->CCR ,0) ;
		break ;
	case DMA_CH6 :
		CLR_BIT(DMA_CH6_BASE->CCR ,0) ;
		break ;
	case DMA_CH7 :
		CLR_BIT(DMA_CH7_BASE->CCR ,0) ;
		break ;
	default :
		/* invalid parameter */
	}
}

/* DMA Start Transfer */
void DMA_SetAddress(Channel_DMA Copy_Channel, void *Copy_pBuffer,
		void *Copy_pPeripheral, uint16 Copy_NumOfElemnts, Size_DMA Copy_Size) {

	switch (Copy_Channel){
	case DMA_CH1 :
		DMA_SetAddress_Help(DMA_CH1_BASE, Copy_pBuffer, Copy_pPeripheral,
				Copy_NumOfElemnts, Copy_Size);
		break ;
	case DMA_CH2 :
		DMA_SetAddress_Help(DMA_CH2_BASE, Copy_pBuffer, Copy_pPeripheral,
				Copy_NumOfElemnts, Copy_Size);
		break ;
	case DMA_CH3 :
		DMA_SetAddress_Help(DMA_CH3_BASE, Copy_pBuffer, Copy_pPeripheral,
				Copy_NumOfElemnts, Copy_Size);
		break ;
	case DMA_CH4 :
		DMA_SetAddress_Help(DMA_CH4_BASE, Copy_pBuffer, Copy_pPeripheral,
				Copy_NumOfElemnts, Copy_Size);
		break ;
	case DMA_CH5 :
		DMA_SetAddress_Help(DMA_CH5_BASE, Copy_pBuffer, Copy_pPeripheral,
				Copy_NumOfElemnts, Copy_Size);
		break ;
	case DMA_CH6 :
		DMA_SetAddress_Help(DMA_CH6_BASE, Copy_pBuffer, Copy_pPeripheral,
				Copy_NumOfElemnts, Copy_Size);
		break ;
	case DMA_CH7 :
		DMA_SetAddress_Help(DMA_CH7_BASE, Copy_pBuffer, Copy_pPeripheral,
				Copy_NumOfElemnts, Copy_Size);
		break ;
	default :
		/* invalid parameter */
	}
}

void DMA_SetAddress_Help(DMA_REG *DMA_Base, void *Copy_pBuffer,
		void *Copy_pPeripheral, uint16 Copy_NumOfElemnts, uint8 Copy_Size){
	switch (Copy_Size){
	case Size_8Bits :
		DMA_Base->CMAR  = (uint8*) Copy_pBuffer ;
		DMA_Base->CPAR  = (uint8*) Copy_pPeripheral ;
		break ;
	case Size_16Bits :
		DMA_Base->CMAR  = (uint16*) Copy_pBuffer ;
		DMA_Base->CPAR  = (uint16*) Copy_pPeripheral ;
		SET_BIT(DMA_Base->CCR,8) ;
		SET_BIT(DMA_Base->CCR,10) ;
		break ;
	case Size_32Bits :
		DMA_Base->CMAR  = (uint32*) Copy_pBuffer ;
		DMA_Base->CPAR  = (uint32*) Copy_pPeripheral ;
		SET_BIT(DMA_Base->CCR,9) ;
		SET_BIT(DMA_Base->CCR,11) ;
		break ;
	default :
		/* Invalid Input */
	}
	DMA_Base->CNDTR = Copy_NumOfElemnts ;
}

void DMA_ClearFlag(Channel_DMA Copy_Channel ,uint8 Copy_FLAG) {
	SET_BIT(DMA_CH1_BASE->IFCR, (Copy_FLAG+ISR_REG_BASE*Copy_Channel) );
}


/* DMA Channel Status Check */
FlagStatus DMA_GetFlagStatus(Channel_DMA Copy_Channel ,Int_Type Copy_FLAG) {
	uint8 Local_FlagState = GET_BIT(DMA_CH1_BASE->ISR,
			(Copy_FLAG+ISR_REG_BASE*Copy_Channel) );
	return Local_FlagState;
}
