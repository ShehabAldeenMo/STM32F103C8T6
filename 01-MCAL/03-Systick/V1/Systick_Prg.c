/*
 * Systick_Prg.c
 *
 *  Created on: Jul 26, 2023
 *      Author: HP
 */


#include "Systick_Interface.h"
#include "Systick_Private.h"
#include "Systick_Cfg.h"

uint8 SingleIntervalFlag = 0 ;

void MSTK_voidInit(void){
	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk ;
}

void MSTK_voidSetBusyWait( uint32 Copy_u32Ticks ){

    // Clear the current value register
    SysTick->VAL = 0;

    // Load the number of ticks to wait
    SysTick->LOAD = Copy_u32Ticks;

    /* to begin counting */
	SET_BIT(SysTick->CTRL,SYSTICK_CTRL_ENABLE);

    // Wait until the COUNTFLAG becomes 1 (indicating the time has elapsed)
    while (GET_BIT(SysTick->CTRL,SYSTICK_CTRL_COUNTFLAG) == 0);

    /* to begin counting */
    CLR_BIT(SysTick->CTRL,SYSTICK_CTRL_ENABLE);
}

void MSTK_voidSetSingleInterval  ( uint32 Copy_u32Ticks, void (*Copy_ptr)(void) ){
    // Load the number of ticks to wait
    SysTick->LOAD = Copy_u32Ticks;

    // Clear the current value register
    SysTick->VAL = 0;

    //to set the call back pointer
    if (Copy_ptr == NULL_PTR){
    	Det_ReportError(0x12, 0x11 , 0x14 );
    }
    else {
    	SysTickCallback = Copy_ptr ;
    }

    /* to mark that you enter this function */
    SingleIntervalFlag = 1 ;

    /* to begin counting */
	SET_BIT(SysTick->CTRL,SYSTICK_CTRL_TICKINT);
	SET_BIT(SysTick->CTRL,SYSTICK_CTRL_ENABLE);
}

void MSTK_voidSetPeriodicInterval( uint32 Copy_u32Ticks, void (*Copy_ptr)(void) ){
    // Load the number of ticks to wait
    SysTick->LOAD = Copy_u32Ticks - 1;

    // Clear the current value register
    SysTick->VAL = 0;

    //to set the call back pointer
    if (Copy_ptr == NULL_PTR){
    	Det_ReportError(0x12, 0x11 , 0x14 );
    }
    else {
    	SysTickCallback = Copy_ptr ;
    }

    /* to begin counting */
	SET_BIT(SysTick->CTRL,SYSTICK_CTRL_TICKINT);
	SET_BIT(SysTick->CTRL,SYSTICK_CTRL_ENABLE);
}

void MSTK_voidStopInterval(void){
    // Disable the SysTick timer and clear the interrupt
    SysTick->CTRL = 0x00000000;

    // Clear the current value register
    SysTick->VAL = 0;
}


uint32  MSTK_u32GetElapsedTime(void){
    // Calculate the elapsed time using the reload value and the current value
    return (SysTick->LOAD - SysTick->VAL);
}


void SysTick_Handler(void){

    // Call the callback function (if set) to handle the SysTick interrupt
    if (SysTickCallback != NULL_PTR)
    {
    	SysTickCallback();
    }
    else {
    	Det_ReportError(0x12, 0x11 , 0x14 );
    }

    /* to stop continues counting in single interval mode */
    if (SingleIntervalFlag == 1){
    	CLR_BIT(SysTick->CTRL,SYSTICK_CTRL_TICKINT);
    	CLR_BIT(SysTick->CTRL,SYSTICK_CTRL_ENABLE);

    	SingleIntervalFlag = 0 ;
    }

    /* to clear flag */
    CLR_BIT(SysTick->CTRL,SYSTICK_CTRL_COUNTFLAG);
}
