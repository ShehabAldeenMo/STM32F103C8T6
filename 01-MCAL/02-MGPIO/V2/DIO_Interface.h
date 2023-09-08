/**
*@file       DIO_Interface.h
*@version    1.0.0
*@brief      AUTOSAR Base - MCAL General purpose input output.
*@details    It contains all prototypes of used functions and states
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
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/****************************************************************************
*****************************  Includes   ***********************************
*****************************************************************************/
#include <Det.h>
#include "Std_Types.h"
#include "../../LIB/BIT_MATH.h"

/****************************************************************************
****************************  typedef   *************************************
*****************************************************************************/

/**
 * Cover_req_[SWS_Dio_00182]
 * Cover_req_[SWS_Dio_00015]
 * Cover_req_[SWS_Dio_00017]
 */
/* we need to Port_PinType with port driver */
typedef enum {
	Dio_A0   = 0x00 ,
	Dio_A1   = 0x01 ,
	Dio_A2   = 0x02 ,
	Dio_A3   = 0x03 ,
	Dio_A4   = 0x04 ,
	Dio_A5   = 0x05 ,
	Dio_A6   = 0x06 ,
	Dio_A7   = 0x07 ,
	Dio_A8   = 0x08 ,
	Dio_A9   = 0x09 ,
	Dio_A10  = 0x0A ,
	Dio_A11  = 0x0B ,
	Dio_A12  = 0x0C ,
	Dio_A14  = 0x0E ,
	Dio_A15  = 0x0F ,

	Dio_B0   = 0x10 ,
	Dio_B1   = 0x11 ,
	Dio_B3   = 0x13 ,
	Dio_B4   = 0x14 ,
	Dio_B5   = 0x15 ,
	Dio_B6   = 0x16 ,
	Dio_B7   = 0x17 ,
	Dio_B8   = 0x18 ,
	Dio_B9   = 0x19 ,
	Dio_B10  = 0x1A ,
	Dio_B11  = 0x1B ,
	Dio_B12  = 0x1C ,
	Dio_B13  = 0x1D ,
	Dio_B14  = 0x1E ,
	Dio_B15  = 0x1F ,

	Dio_C14  = 0x2E ,
	Dio_C15  = 0x2F
}Dio_ChannelType;

/**
 * Cover_req_[SWS_Dio_00183]
 * Cover_req_[SWS_Dio_00018]
 * Cover_req_[SWS_Dio_00181]
 * Cover_req_[SWS_Dio_00020]
 */
typedef enum {
	Dio_GPIO_A ,
	Dio_GPIO_B ,
	Dio_GPIO_C ,
}Dio_PortType;


/**
 * Cover_req_[SWS_Dio_00185]
 * Cover_req_[SWS_Dio_00186]
 */
typedef uint8  Dio_LevelType;            /* Range: STD_LOW, STD_HIGH */

typedef uint16 Dio_PortLevelType;        /* Range:If the µC owns ports of different port widths
                                           (e.g. 4, 8,16...Bit) Dio_PortLevelType inherits the size
                                           of the largest port*/


/****************************************************************************
********************* Function definitions **********************************
*****************************************************************************/

/**
 * Cover_req_[SWS_Dio_00133]
 * Cover_req_[SWS_Dio_00028]
 * Cover_req_[SWS_Dio_00029]
 * Cover_req_[SWS_Dio_00079]
 * Cover_req_[SWS_Dio_00136]
 * Cover_req_[SWS_Dio_00139]
 * Cover_req_[SWS_Dio_00190]
 */
Dio_LevelType     Dio_ReadChannel (Dio_ChannelType ChannelId)                         ;
void              Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level)     ;
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)                                   ;
void              Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level)          ;
void              Dio_GetVersionInfo(Std_VersionInfoType* versioninfo)                ;
Dio_LevelType     Dio_FlipChannel(Dio_ChannelType ChannelId)                          ;



#endif /* DIO_INTERFACE_H_ */
