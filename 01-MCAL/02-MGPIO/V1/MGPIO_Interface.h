/*
 * file            : GPIO_Interface.h
 * author          : Shehab aldeen
 * brief           :
*/

#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_

#include <DET.h>

#include "../../LIB/STD_TYPES.h"

typedef enum {
	GPIO_A ,
	GPIO_B ,
	GPIO_C ,
	GPIO_D
}GPIO_X;

typedef enum {
	PIN_0_  ,
	PIN_1_  ,
	PIN_2_  ,
	PIN_3_  ,
	PIN_4_  ,
	PIN_5_  ,
	PIN_6_  ,
	PIN_7_  ,
	PIN_8_  ,
	PIN_9_  ,
	PIN_10_ ,
	PIN_11_ ,
	PIN_12_ ,
	PIN_13_ ,
	PIN_14_ ,
	PIN_15_
}PIN_X_;

typedef enum {
	INPUT            =     0x0 , /*00: Input mode*/
	OUTPUT_10        =     0x1 , /*01 : Output mode, max speed 10 MHz. */
	OUTPUT_2         =     0x2 , /*10 : Output mode, max speed 2 MHz. */
	OUTPUT_50        =     0x3 , /*11 : Output mode, max speed 50 MHz. */

	/* In output mode (MODE[1:0] > 00) : */
	G_PUSH_PULL      =     0x0 , /*00: General purpose output push-pull */
	G_OPEN_DRAIN     =     0x4 , /*01: General purpose output Open-drain*/
	A_PUSH_PULL      =     0x8 , /*10: Alternative purpose output push-pull */
	A_OPEN_DRAIN     =     0xC , /*11: Alternative purpose output Open-drain*/
	NONE_OUTPUT      =     0x0 ,

	/*  In input mode (MODE[1:0]=00): */
	ANA_MODE         =     0x0  ,
	FLOATING_INPUT   =     0x4  ,
	INPUT_PULL_DOWN  =     0x8  ,
	NONE_INPUT       =     0x0
}PIN_MODE;


typedef struct {
	GPIO_X      GPIO_PORT          ;
	PIN_X_      PIN_NUM            ;
	PIN_MODE    PIN_MODE_Direction ;
	PIN_MODE    I_O_MODE_PIN       ;
}PIN_CONFIGURATION;

#define HIGH           1
#define LOW            0
#define GPIO_MODULE_ID  0x78

Std_ReturnType GPIOX_VidSetPinDirection      (const PIN_CONFIGURATION* config_ptr )                      ;
Std_ReturnType GPIOX_VidSetPinValue          (const PIN_CONFIGURATION* config_ptr, u8 Copy_Pin_Value )   ;
Std_ReturnType GPIOX_VidTogglePinValue       (const PIN_CONFIGURATION* config_ptr, u64 *Copy_Delay_Time );
u8   GPIOX_U8GetPinValue           (const PIN_CONFIGURATION* config_ptr , Std_ReturnType* Copy_State)    ;
Std_ReturnType GPIOX_VidSetPortDirectionLow  (u8 Copy_GPIOX , u8 Copy_Port_Purpose )                     ;
Std_ReturnType GPIOX_VidSetPortDirectionHigh (u8 Copy_GPIOX , u8 Copy_Port_Purpose )                     ;
Std_ReturnType GPIOX_VidLockPort             (u8 Copy_GPIOX )                                            ;
Std_ReturnType GPIOX_VidResetPort            (u8 Copy_GPIOX )                                            ;
Std_ReturnType GPIOX_VidSetPortValue         (u8 Copy_GPIOX ,u8 Copy_Port_Value )                        ;

#endif /* MGPIO_INTERFACE_H_ */
