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

/**
 * \section Brief
 * This function configure DMA channel.
 *
 * \section Re-enterancy
 * Re-Entrant
 *
 * \section Scoope
 * Public
 *
 * \param[in]     Configuration_DMA  \ Type struct  \ Range determine from Configuration_DMA \ Resolution inapplicable \ unit block of memory
 * \param[out]    None
 * \param[in,out] None
 * \return        None
 *
 * \section Sequence
 *
 * @startuml
 *
 * footer Page %page% of %lastpage%
 *
 * title Sequency diagram
 *
 * DMA_Config ->  :
 *
 * @enduml
 */
void DMA_Config(const Configuration_DMA *Config_Ptr){
	/**
	 * \section Activity
	 *
	 * @startuml
	 *   start
	 *   switch (Which DMA channel is activited)
	 *   case ( condition channel1 )
	 *     #green:Set configurations of channel1;
	 *   case ( condition channel2 )
	 *     #green:Set configurations of channel2;
	 *   case ( condition channel3 )
	 *     #green:Set configurations of channel3;
	 *   case ( condition channel4 )
	 *     #green:Set configurations of channel4;
	 *   case ( condition channel5 )
	 *     #green:Set configurations of channel5;
	 *   case ( condition channel6 )
	 *     #green:Set configurations of channel6;
	 *   case ( condition channel7 )
	 *     #green:Set configurations of channel7;
	 *   case ( default )
	 *     #red:Det_ReportError(infinite loop);
	 *     end
	 * endswitch
	 * end
	 * @enduml
	 */
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
		Det_ReportError(0x00, 0x00, 0x00);
	}
}

/**
 * \section Brief
 * This function enables DMA channel.
 *
 * \section Re-enterancy
 * Re-Entrant
 *
 * \section Scoope
 * Public
 *
 * \param[in]     Channel_DMA  \ Type enum  \ Range determine from Channel_DMA \ Resolution inapplicable \ unit bits
 * \param[out]    None
 * \param[in,out] None
 * \return        None
 *
 * \section Sequence
 *
 * @startuml
 *
 * footer Page %page% of %lastpage%
 *
 * title Sequency diagram
 *
 * DMA_ChannelEnable ->  :
 *
 * @enduml
 */
void DMA_ChannelEnable(Channel_DMA Copy_Channel){
	/**
	 * \section Activity
	 *
	 * @startuml
	 *   start
	 *   switch (Which DMA channel is activited)
	 *   case ( condition channel1 )
	 *     #green:Turn on channel1;
	 *   case ( condition channel2 )
	 *     #green:Turn on channel2;
	 *   case ( condition channel3 )
	 *     #green:Turn on channel3;
	 *   case ( condition channel4 )
	 *     #green:Turn on channel4;
	 *   case ( condition channel5 )
	 *     #green:Turn on channel5;
	 *   case ( condition channel6 )
	 *     #green:Turn on channel6;
	 *   case ( condition channel7 )
	 *     #green:Turn on channel7;
	 *   case ( default )
	 *     #red:Det_ReportError(infinite loop);
	 *     end
	 * endswitch
	 * end
	 * @enduml
	 */
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
		Det_ReportError(0x00, 0x00, 0x00);
	}
}

/**
 * \section Brief
 * This function disables DMA channel.
 *
 * \section Re-enterancy
 * Re-Entrant
 *
 * \section Scoope
 * Public
 *
 * \param[in]     Channel_DMA  \ Type enum  \ Range determine from Channel_DMA \ Resolution inapplicable \ unit bits
 * \param[out]    None
 * \param[in,out] None
 * \return        None
 *
 * \section Sequence
 *
 * @startuml
 *
 * footer Page %page% of %lastpage%
 *
 * title Sequency diagram
 *
 * DMA_ChannelEnable -> CLR_BIT  : Clear bit Request
 * CLR_BIT --> DMA_ChannelEnable : Clearing specified bit response
 *
 * @enduml
 */
void DMA_ChannelDisable(Channel_DMA Copy_Channel){
	/**
	 * \section Activity
	 *
	 * @startuml
	 *   start
	 *   switch (Which DMA channel is activited)
	 *   case ( condition channel1 )
	 *     #green:Turn off channel1;
	 *   case ( condition channel2 )
	 *     #green:Turn off channel2;
	 *   case ( condition channel3 )
	 *     #green:Turn off channel3;
	 *   case ( condition channel4 )
	 *     #green:Turn off channel4;
	 *   case ( condition channel5 )
	 *     #green:Turn off channel5;
	 *   case ( condition channel6 )
	 *     #green:Turn off channel6;
	 *   case ( condition channel7 )
	 *     #green:Turn off channel7;
	 *   case ( default )
	 *     #red:Det_ReportError(infinite loop);
	 *     end
	 * endswitch
	 * end
	 * @enduml
	 */
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
		Det_ReportError(0x00, 0x00, 0x00);
	}
}

/**
 * \section Brief
 * This function set address for each DMA channel that used in transformation data between them.
 *
 * \section Re-enterancy
 * Re-Entrant
 *
 * \section Scoope
 * Public
 *
 * \param[in]     Copy_Channel      \ Type enum             \ Range determine from Channel_DMA \ Resolution inapplicable \ unit bits
 * \param[in]     Copy_pBuffer      \ Type pointer to void  \ Range generic pointer            \ Resolution inapplicable \ unit bits
 * \param[in]     Copy_pPeripheral  \ Type pointer to void  \ Range generic pointer            \ Resolution inapplicable \ unit bits
 * \param[in]     Copy_NumOfElemnts \ Type uint16           \ Range 0:65636                    \ Resolution inapplicable \ unit bits
 * \param[in]     Copy_Size         \ Type enum             \ Range determine from Size_DMA    \ Resolution inapplicable \ unit bits
 * \param[out]    None
 * \param[in,out] None
 * \return        None
 *
 * \section Sequence
 *
 * @startuml
 *
 * footer Page %page% of %lastpage%
 *
 * title Sequency diagram
 *
 * DMA_SetAddress -> DMA_SetAddress_Help  : Configure perapheral address, Memory address, Element size, DMA channel Request
 * DMA_SetAddress_Help --> DMA_SetAddress : Configuration response
 *
 * @enduml
 */
void DMA_SetAddress(Channel_DMA Copy_Channel, void *Copy_pBuffer,
		void *Copy_pPeripheral, uint16 Copy_NumOfElemnts, Size_DMA Copy_Size) {

	/**
	 * \section Activity
	 *
	 * @startuml
	 *   start
	 *   switch (Which DMA channel is activited)
	 *   case ( condition channel1 )
	 *     #green:call DMA_SetAddress_Help for channel1;
	 *   case ( condition channel2 )
	 *     #green:call DMA_SetAddress_Help for channel2;
	 *   case ( condition channel3 )
	 *     #green:call DMA_SetAddress_Help for channel3;
	 *   case ( condition channel4 )
	 *     #green:call DMA_SetAddress_Help for channel4;
	 *   case ( condition channel5 )
	 *     #green:call DMA_SetAddress_Help for channel5;
	 *   case ( condition channel6 )
	 *     #green:call DMA_SetAddress_Help for channel6;
	 *   case ( condition channel7 )
	 *     #green:call DMA_SetAddress_Help for channel7;
	 *   case ( default )
	 *     #red:Det_ReportError(infinite loop);
	 *     end
	 * endswitch
	 * end
	 * @enduml
	 */
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
		Det_ReportError(0x00, 0x00, 0x00);
	}
}

/**
 * \section Brief
 * This function return flag state of DMA channel interrupt.
 *
 * \section Re-enterancy
 * Re-Entrant
 *
 * \section Scoope
 * Private
 *
 * \param[in]     Copy_DMA_Base      \ Type pointer to structure  \ Range 0x40020000 : 0x4002008C \ Resolution 0x04         \ unit Address
 * \param[in]     Copy_pBuffer       \ Type address               \ Range Unapplicable            \ Resolution Unapplicable \ unit Address
 * \param[in]     Copy_pPeripheral   \ Type address               \ Range Unapplicable            \ Resolution Unapplicable \ unit Address
 * \param[in]     Copy_NumOfElemnts  \ Type uint16                \ Range 0:65536                 \ Resolution 1            \ unit elements
 * \param[in]     Copy_Size          \ Type uint8                \ Range 0:2                      \ Resolution 1            \ unit size of element
 * \param[out]    None
 * \param[in,out] None
 * \return        None
 *
 * \section Sequence
 *
 * @startuml
 *
 * footer Page %page% of %lastpage%
 *
 * title Sequency diagram
 *
 * DMA_SetAddress_Help ->   :
 *
 * @enduml
 */
void DMA_SetAddress_Help(DMA_REG *DMA_Base, void *Copy_pBuffer,
		void *Copy_pPeripheral, uint16 Copy_NumOfElemnts, uint8 Copy_Size){

	/**
	 * \section Activity
	 *
	 * @startuml
	 *   start
	 *   switch (Which DMA channel is activited)
	 *   case ( condition channel1 )
	 *     #green:Set peripheral address, memory address and element size
	 *     that transimittied between them using channel1;
	 *   case ( condition channel2 )
	 *     #green:Set peripheral address, memory address and element size
	 *     that transimittied between them using channel2;
	 *   case ( condition channel3 )
	 *     #green:Set peripheral address, memory address and element size
	 *     that transimittied between them using channel3;
	 *   case ( condition channel4 )
	 *     #green:Set peripheral address, memory address and element size
	 *     that transimittied between them using channel4;
	 *   case ( condition channel5 )
	 *     #green:Set peripheral address, memory address and element size
	 *     that transimittied between them using channel5;
	 *   case ( condition channel6 )
	 *     #green:Set peripheral address, memory address and element size
	 *     that transimittied between them using channel6;
	 *   case ( condition channel7 )
	 *     #green:Set peripheral address, memory address and element size
	 *     that transimittied between them using channel7;
	 *   case ( default )
	 *     #red:Det_ReportError(infinite loop);
	 *     end
	 * endswitch
	 * end
	 * @enduml
	 */
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
		Det_ReportError(0x00, 0x00, 0x00);
	}
	DMA_Base->CNDTR = Copy_NumOfElemnts ;
}

/**
 * \section Brief
 * This function clear flag of DMA channel interrupt.
 *
 * \section Re-enterancy
 * Re-Entrant
 *
 * \section Scoope
 * Public
 *
 * \param[in]     Channel_DMA  \ Type enum  \ Range determine from Channel_DMA \ Resolution inapplicable \ unit bits
 * \param[in]     Copy_FLAG    \ Type uint8 \ Range 1:7                        \ Resolution 1            \ unit bits
 * \param[out]    None
 * \param[in,out] None
 * \return        None
 *
 * \section Sequence
 *
 * @startuml
 *
 * footer Page %page% of %lastpage%
 *
 * title Sequency diagram
 *
 * DMA_ClearFlag -> SET_BIT  : Setting bit Request to clear flag
 * SET_BIT --> DMA_ClearFlag : Sething specified bit response
 *
 * @enduml
 */
void DMA_ClearFlag(Channel_DMA Copy_Channel ,uint8 Copy_FLAG) {
	/**
	 * \section Activity
	 *
	 * @startuml
	 *   start
	 *  :clear flag by setting the flag bit interrupt;
	 * end
	 * @enduml
	 *
	 */
	SET_BIT(DMA_CH1_BASE->IFCR, (Copy_FLAG+ISR_REG_BASE*Copy_Channel) );
}



/**
 * \section Brief
 * This function return flag state of DMA channel interrupt.
 *
 * \section Re-enterancy
 * Re-Entrant
 *
 * \section Scoope
 * Public
 *
 * \param[in]     Channel_DMA  \ Type enum  \ Range determine from Channel_DMA \ Resolution inapplicable \ unit bits
 * \param[in]     Copy_FLAG    \ Type uint8 \ Range 1:7                        \ Resolution 1            \ unit bits
 * \param[out]    None
 * \param[in,out] None
 * \return        None
 *
 * \section Sequence
 *
 * @startuml
 *
 * footer Page %page% of %lastpage%
 *
 * title Sequency diagram
 *
 * DMA_GetFlagStatus ->   :
 *
 * @enduml
 */
FlagStatus DMA_GetFlagStatus(Channel_DMA Copy_Channel ,Int_Type Copy_FLAG) {
	/**
	 * \section Activity
	 *
	 * @startuml
	 *   start
	 *  :Read flag of interrupt;
	 * end
	 * @enduml
	 *
	 */
	uint8 Local_FlagState = GET_BIT(DMA_CH1_BASE->ISR,
			(Copy_FLAG+ISR_REG_BASE*Copy_Channel) );
	return Local_FlagState;
}
