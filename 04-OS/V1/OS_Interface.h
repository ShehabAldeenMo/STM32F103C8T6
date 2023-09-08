/*
 * OS_Interface.h
 *
 *  Created on: Aug 18, 2023
 *      Author: HP
 */

#include "Std_Types.h"
#include "Bit_Math.h"

#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_

#define SUSPEND    0
#define RUNING     1
#define null       0

void create_task (uint8 Copy_periodicity , uint8 Copy_prioirty , void (*Copy_PFUNC)(void) , uint8 Copy_FD , uint8 Copy_State );
void Suspend_Task(uint8 Copy_prioirty);
void Resume_Task (uint8 Copy_prioirty);
void Delete_Task (uint8 Copy_prioirty);
void Schedular(void);

#endif /* OS_INTERFACE_H_ */
