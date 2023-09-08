/*
 * OS_Private.h
 *
 *  Created on: Aug 18, 2023
 *      Author: HP
 */

#ifndef OS_PRIVATE_H_
#define OS_PRIVATE_H_



typedef struct {
	void (*PFUNC)(void);
	uint8 perodicity ;
	uint8 First_delay ;
	uint8 State ;
}TASK_T;

#define MAX_NUM_TASKS  255

#endif /* OS_PRIVATE_H_ */
