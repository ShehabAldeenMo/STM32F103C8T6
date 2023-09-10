/*
*@file       DMA_Interface.h
*@version    1.0.0
*@brief      MCAL Direct meomry access
*@details    It contains the protypes of functions that use in upper layer
*@author     Shehab aldeen mohammed abdalah
*/

/**
 * \mainpage
 * \section Brief
 * This is file includes headers and functions for the DMA
 *
 * \section Details
 * We have six functions explaind in the SoftwareContext
 *
 * \section SoftwareContext
 * This service configure DMA with its diffrent modes,
 * set the address that you used in transformatation, Enable DMA channel.
 * if you want to reconfigure DMA channel or change address, you must disable channel.
 *
 * \section features Features
 *
 * - **Transfer from memory to memory**
 * - **Transfer from memory to peripheral**
 * - **Transfer from peripheral to memory**
 * - **Transfer from peripheral to peripheral**
 *
 * \section Component_History
 *  - **V.1.0.0:** Initial release.
 *
 * \section Creation
 * @startuml
 * json "<b>Creation" as J {
 * "Name": "Shehab aldeen mohammed",
 * "Date": "10/9/2023",
 * "Driver type": "DMA",
 * "Version": "V1.0"
 * }
 * @enduml

 *
 * \section Refrences
 * @startuml
 * json "<b>Refrences" as J {
 * "First refrence": "STM32F103XX Datasheet - STMicroelectronics",
 * "Second refrence": "Web page plantuml.com"
 * }
 * @enduml
 *
 * \section Reviews
 * @startuml
 * json "<b>Reviews" as J {
 * "Ahmed El-shamy": "reviewed",
 * "Karim Ahmed": "Accepted ",
 * "Mahmoud Abou-Yousef": "reviewed"
 * }
 * @enduml
 *
 *
 * \section Functions_Usage
 * @startuml
 * agent DMA
 * DMA --> DMA_Config #line:green;line.bold;text:green  : Settable function
 * DMA --> DMA_SetAddress #line:green;line.bold;text:green  : Settable function
 * DMA --> DMA_ChannelEnable #line:green;line.bold;text:green  : Settable function
 * DMA --> DMA_ChannelDisable #line:green;line.bold;text:green  : Settable function
 * DMA --> DMA_ClearFlag #line:green;line.bold;text:green  : Settable function
 * DMA --> DMA_GetFlagStatus #line:blue;line.bold;text:blue  : Application function
 * @enduml
 *
 */

/**
 * \file DMA_Interface.h
 * Defined data structures and function declarations for the MPU driver.
 *
 * \section Scope
 * Public
 *
 * \section Author
 * Shehab Abdalah
 */

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

#include "Std_Types.h"
#include "Bit_Math.h"

/**
 * \section Brief
 *  Used to enumerate each specification for channels with circular mode or not , peripheral increment or not
 *  and memory increment or not.
 *
 * \section Details
 * (Type enum  \ Range inapplicable  \ Resolution inapplicable \ unit bits )
 *
 */
typedef enum {
	Specs_CIRC_ON  = 0x00000020,
	Specs_CIRC_OFF = 0x00000000,
	Specs_PINC_ON  = 0x00000040,
	Specs_PINC_OFF = 0x00000000,
	Specs_MINC_ON  = 0x00000080,
	Specs_MINC_OFF = 0x00000000
}Specs;

/**
 * \section Brief
 *  Used to enumerate each specification for channels with transmit error interrupt enable or disable
 *   , half transmittion interrupt enable or disable and Total transmition interrupt enable or disable.
 *
 * \section Details
 * (Type enum  \ Range inapplicable  \ Resolution inapplicable \ unit bits )
 *
 */
typedef enum{
	Int_TEIE = 0x00000008 ,
	Int_TEID = 0x00000000 ,
	Int_HTIE = 0x00000004 ,
	Int_HTID = 0x00000000 ,
	Int_TCIE = 0x00000002 ,
	Int_TCID = 0x00000000 ,
}Int_Type;

/**
 * \section Brief
 *  Used to enumerate each channel in DMA1
 *
 * \section Details
 * (Type enum  \ Range inapplicable  \ Resolution inapplicable \ unit bits )
 *
 */
typedef enum{
	DMA_CH1,
	DMA_CH2,
	DMA_CH3,
	DMA_CH4,
	DMA_CH5,
	DMA_CH6,
	DMA_CH7
}Channel_DMA;

/**
 * \section Brief
 *  Used to enumerate each element size in transmition
 *
 * \section Details
 * (Type enum  \ Range inapplicable  \ Resolution inapplicable \ unit bits )
 *
 */
typedef enum {
	Size_8Bits ,
	Size_16Bits,
	Size_32Bits
}Size_DMA;

/**
 * \section Brief
 *  Used to enumerate each channel arbiter "priority" with low or medium or high or very_high
 *
 * \section Details
 * (Type enum  \ Range inapplicable  \ Resolution inapplicable \ unit bits )
 *
 */
typedef enum{
	Arbiter_Low      = 0x00000000 ,
	Arbiter_Medium   = 0x00001000 ,
	Arbiter_High     = 0x00002000 ,
	Arbiter_VeryHigh = 0x00003000 ,
}Arbiter_DMA;

/**
 * \section Brief
 *  Used to enumerate each expected tranformation between address that can be between memory to memory or
 *  memory to peripheral or peripheral to memory or peripheral to peripheral
 *
 * \section Details
 * (Type enum  \ Range inapplicable  \ Resolution inapplicable \ unit bits )
 *
 */
typedef enum{
	Transfer_MEM2MEM = 0x00004010,
	Transfer_MEM2PER = 0x00000010,
	Transfer_PER2PER = 0x00000000,
	Transfer_PER2MEM = 0x00000000
}Tranfer_DMA;

/**
 * \section Brief
 *  Used to make structure of configuration elements that used for each channel
 *
 * \section Details
 * (Type struct  \ Range inapplicable  \ Resolution inapplicable \ unit bits )
 *
 * \section elements
 * Copy_Channel : number of channel
 * TransferType : Transfer type
 * Priority     : priority of each channel
 * INT_Enable   : interrupt flag that used foe ISR
 * CircularMode : Circular mode is enabled or not
 * mIncrement   : memory increment
 * pIncrement   : peripheral increment
 *
 */
typedef struct{
	Channel_DMA      Copy_Channel ;
	Tranfer_DMA      TransferType ;
	Arbiter_DMA      Priority     ;
	Int_Type         INT_Enable   ;
	Specs            CircularMode ;
	Specs            mIncrement   ;
	Specs            pIncrement   ;
}Configuration_DMA;


/**
 * \section Brief
 *  Used to facilit  usage of flages
 *
 * \section Details
 * (Type enum  \ Range inapplicable  \ Resolution inapplicable \ unit bits )
 *
 */
typedef uint8 FlagStatus;

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
 *
 * \section Activity
 *
 */
void DMA_Config(const Configuration_DMA *Config_Ptr);

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
 *
 * \section Activity
 *
 */
void DMA_ChannelEnable(Channel_DMA Copy_Channel);


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
 *
 * \section Activity
 *
 */
void DMA_ChannelDisable(Channel_DMA Copy_Channel);


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
 * \param[in]     Copy_Channel  \ Type enum  \ Range determine from Channel_DMA \ Resolution inapplicable \ unit bits
 * \param[in]     Copy_pBuffer  \ Type pointer to void  \ Range generic pointer \ Resolution inapplicable \ unit bits
 * \param[in]     Copy_pPeripheral  \ Type pointer to void  \ Range generic pointer \ Resolution inapplicable \ unit bits
 * \param[in]     Copy_NumOfElemnts  \ Type uint16 \ Range 0:65636 \ Resolution inapplicable \ unit bits
 * \param[in]     Copy_Size  \ Type enum  \ Range determine from Size_DMA \ Resolution inapplicable \ unit bits
 * \param[out]    None
 * \param[in,out] None
 * \return        None
 *
 * \section Sequence
 *
 *
 * \section Activity
 *
 */
void DMA_SetAddress(Channel_DMA Copy_Channel, void *Copy_pBuffer,
		void *Copy_pPeripheral, uint16 Copy_NumOfElemnts, Size_DMA Copy_Size);


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
 * \param[in]     Copy_FLAG  \ Type uint8  \ Range 1:7 \ Resolution 1 \ unit bits
 * \param[out]    None
 * \param[in,out] None
 * \return        None
 *
 * \section Sequence
 *
 *
 * \section Activity
 *
 */
void DMA_ClearFlag(Channel_DMA Copy_Channel ,uint8 Copy_FLAG);

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
 * \param[in]     Copy_FLAG  \ Type uint8  \ Range 1:7 \ Resolution 1 \ unit bits
 * \param[out]    None
 * \param[in,out] None
 * \return        None
 *
 * \section Sequence
 *
 *
 * \section Activity
 *
 */
FlagStatus DMA_GetFlagStatus(Channel_DMA Copy_Channel ,Int_Type Copy_FLAG);


#endif /* DMA_INTERFACE_H_ */
