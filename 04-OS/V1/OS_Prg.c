/*
 * OS_Prg.c
 *
 *  Created on: Aug 18, 2023
 *      Author: HP
 */
#include "OS_Interface.h"
#include "OS_Cfg.h"
#include "OS_Private.h"


//array of tasks
TASK_T sys_tasks [MAX_NUM_TASKS] ;

void Schedular(void){
	for (uint8 i = 0 ; i < NUM_TASKS ; i++){
		if (sys_tasks[i].State == RUNING ){
			if( sys_tasks[i].First_delay == 1 ){
					sys_tasks[i].PFUNC();
					sys_tasks[i].First_delay = sys_tasks[i].perodicity ;
			}//end if sys_tasks[i].First_delay == 1
			else {
				sys_tasks[i].First_delay-- ;
			}//end else
		}//end if sys_tasks[i].State == RUNING
	}//end for (uint8 i = 0 ; i < NUM_TASKS ; i++)
}//end FUNC Schedular

void create_task (uint8 Copy_periodicity , uint8 prioirty ,void (*Copy_PFUNC)(void), uint8 Copy_FD,  uint8 Copy_State  ){
	sys_tasks [prioirty].perodicity  = Copy_periodicity ;
	sys_tasks [prioirty].PFUNC       = Copy_PFUNC       ;
	sys_tasks [prioirty].First_delay = Copy_FD          ;
	sys_tasks [prioirty].State       = Copy_State       ;
}

void Suspend_Task(uint8 Copy_prioirty){
	sys_tasks [Copy_prioirty].State = SUSPEND ;
}
void Resume_Task(uint8 Copy_prioirty){
	sys_tasks [Copy_prioirty].State = RUNING ;
}
void Delete_Task (uint8 Copy_prioirty){
	sys_tasks [Copy_prioirty].PFUNC = null ;
}


