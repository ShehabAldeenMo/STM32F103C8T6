/**
*@file       EXTIx_Prg.c
*@version    1.0.0
*@brief      MCAL ................
*@details    ...........................
*@author     Shehab aldeen mohammed abdalah
*/

#include "EXTIx_Interface.h"
#include "EXTIx_Private.h"

void EXTI_ConfigLine  (EXTI_Enum EXTI_Line ,PIN_Enum PIN  ,IntOrEventActive_Enum IntOrEveActive,uint8 edge){

	if ( !(EXTI_Line >= EXTI0_ && EXTI_Line <= EXTI15_)
		|| !(PIN >=PINAx && PIN<=PINCx)
		|| !(IntOrEveActive >=EXTI0_INT_Active &&IntOrEveActive<=EXTI15_Event_Active  )
	){
		Det_ReportError(0x11, 0x12, 0x13);   //random
	}

	uint8 EXTI_NUM = EXTI_Line / 4 ;

	switch (EXTI_NUM){
	case 0 :
		AFIO->EXTICR1 = ( PIN << EXTI_Line*4 );
		break;
	case 1 :
		AFIO->EXTICR2 = ( PIN<< (EXTI_Line%EXTI4_)*4 );
		break;
	case 2 :
		AFIO->EXTICR3 = ( PIN<< (EXTI_Line%EXTI4_)*4  );
		break;
	case 3 :
		AFIO->EXTICR4 = ( PIN<< (EXTI_Line%EXTI4_)*4  );
		break;
	default :
		Det_ReportError(0x11, 0x12, 0x13);   //random
		break;
	}

	if (IntOrEveActive >=EXTI0_INT_Active &&IntOrEveActive<=EXTI15_INT_Active){
		EXTI->IMR     = IntOrEveActive ;
	}
	else if (IntOrEveActive >=EXTI0_Event_Active &&IntOrEveActive<=EXTI15_Event_Active  ){
		CLR_BIT(IntOrEveActive,16);
		EXTI->EMR = IntOrEveActive ;
	}

	switch (edge){
	case FALLING_EDGE :
		SET_BIT(EXTI->FTSR,EXTI_Line);
		break;
	case RISING_EDGE  :
		SET_BIT(EXTI->RTSR,EXTI_Line);
		break;
	case BOTH_EDGES   :
		SET_BIT(EXTI->RTSR,EXTI_Line);
		SET_BIT(EXTI->FTSR,EXTI_Line);
		break;
	default :
		Det_ReportError(0x11, 0x12, 0x13);   //random
		break;
	}
}
void EXTI_SW_InterruptEnable     (Flag_Enum Copy_uint8Flag){
	if (Copy_uint8Flag >=EXTI0_Flag && Copy_uint8Flag<=EXTI15_Flag){
		EXTI->SWIER   = Copy_uint8Flag ;
	}
	else {
		Det_ReportError(0x11, 0x12, 0x13);   //random
	}
}
void EXTI_ClearPending           (Flag_Enum Copy_uint8Flag){
	if (Copy_uint8Flag >=EXTI0_Flag && Copy_uint8Flag<=EXTI15_Flag){
		EXTI->PR      = Copy_uint8Flag ;
	}
	else {
		Det_ReportError(0x11, 0x12, 0x13);   //random
	}

}
