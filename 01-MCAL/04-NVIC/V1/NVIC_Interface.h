/**
*@file       NVIC_Interface.h
*@version    1.0.0
*@brief      MCAL Nested vectored interrupt controller .
*@details    It contains all prototypes of used functions and states
*@author     Shehab aldeen mohammed abdalah
*/


/*
 Driver need to commenting functions and some edits
  */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

#include "Std_Types.h"
#include "Bit_Math.h"
#include "Det.h"

typedef enum {
	WWDG,
	PVD,
	TAMPER,
	RTC,
	FLASH,
	RCC,
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	DMA1_Channel1,
	DMA1_Channel2,
	DMA1_Channel3,
	DMA1_Channel4,
	DMA1_Channel5,
	DMA1_Channel6,
	DMA1_Channel7,
	ADC1_2,
	CAN1_TX,
	CAN1_RX0,
	CAN1_RX1,
	CAN1_SCE,
	EXTI9_5,
	TIM1_BRK,
	TIM1_UP,
	TIM1_TRG_COM,
	TIM1_CC,
	TIM2,
	TIM3,
	TIM4,
	I2C1_EV,
	I2C1_ER,
	I2C2_EV,
	I2C2_ER,
	SPI1,
	SPI2,
	USART1,
	USART2,
	USART3,
	EXTI15_10,
    RTCAlarm,
    OTG_FS_WKUP,
    Reserved,
    TIM5 = 50 ,
    SPI3,
    UART4,
    UART5,
    TIM6,
    TIM7,
    DMA2_Channel1,
    DMA2_Channel2,
    DMA2_Channel3,
    DMA2_Channel4,
    DMA2_Channel5,
    ETH,
    ETH_WKUP,
    CAN2_TX,
    CAN2_RX0,
    CAN2_RX1,
    CAN2_SCE,
    OTG_FS
} IRQn_Type;

#define SIXTEEN_GROUPS_ZERO_SUB  	 	0x5FA00300
#define EIGHT_GROUPS_TWO_SUB  	  		0x5FA00400
#define FOUR_GROUPS_FOUR_SUB  	  		0x5FA00500
#define TWO_GROUPS_EIGHT_SUB  	  		0x5FA00600
#define ZERO_GROUPS_SIXTEEN_SUB  	  	0x5FA00700



/* Enable an interrupt */
void MNVIC_EnableIRQ(IRQn_Type IRQn);

/* Disable an interrupt */
void MNVIC_DisableIRQ(IRQn_Type IRQn);

/* enable pending an interrupt */
void MNVIC_PendingEnableIRQ(IRQn_Type IRQn);

/* disable pending an interrupt */
void MNVIC_PendingDisableIRQ(IRQn_Type IRQn);

/* to determine active flag state of interrupt */
uint8 MNVIC_GetActive(IRQn_Type IRQn);

/* Set the priority of an interrupt */
void MNVIC_SetPriority(IRQn_Type IRQn, uint8 priority);

/*to set the number of groups*/
void MNVIC_SetPriorityGroup (uint32 NumOfGroups);

/* to read the state of pending flag */
uint8 MNVIC_GetStatePendingIRQ(IRQn_Type IRQn);

/* to read the state of enable flag */
uint8 MNVIC_GetStateEnableIRQ(IRQn_Type IRQn  );

/* Get the priority of an interrupt */
uint8  MNVIC_GetPriority(IRQn_Type IRQn);

/*to set call back function*/
void  MNVIC_SetCallBackFunc (uint8 INT_Position,void (*Copy_ptr)(void));

/* to get info of diver */
void  NVIC_GetVersionInfo(Std_VersionInfoType* versioninfo);

#endif /* NVIC_INTERFACE_H_ */
