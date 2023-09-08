/*
 * file            : GPIO.c
 * author          : Shehab aldeen
 * brief           :
*/

#include <MGPIO_Interface.h>
#include <MGPIO_Private.h>

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/*
  Input  :
  output :
  description :To select the type of pin
	In input mode (MODE[1:0]=00):
	00: Analog mode
	01: Floating input (reset state)
	10: Input with pull-up / pull-down
	11: Reserved

	In output mode (MODE[1:0] > 00):
	00: General purpose output push-pull
	01: General purpose output Open-drain
	10: Alternate function output Push-pull
	11: Alternate function output Open-drain

	MODEy[1:0]
	00: Input mode (reset state)
	01: Output mode, max speed 10 MHz.
	10: Output mode, max speed 2 MHz.
	11: Output mode, max speed 50 MHz

*/
Std_ReturnType GPIOX_VidSetPinDirection      (const PIN_CONFIGURATION* config_ptr )
{
	/**/
	Std_ReturnType STATE = OK ;

	/* check on coming pointer */
	if (NULL == config_ptr){
		STATE = NULL_PTR ;
		return STATE ;
	}

	u8  LOCAL_Pin_Purpose = config_ptr->I_O_MODE_PIN | config_ptr->PIN_MODE_Direction ;

	switch (config_ptr->GPIO_PORT)
	{
	case GPIO_A :
		if (config_ptr->PIN_NUM < 8 ){
			GPIOA->CRL &= ~((0xF) << ( config_ptr->PIN_NUM * BASE_CRL_CRH));
			GPIOA->CRL |= ( LOCAL_Pin_Purpose <<(config_ptr->PIN_NUM  * BASE_CRL_CRH) ) ;
		}
		else if (config_ptr->PIN_NUM   >= 8  && config_ptr->PIN_NUM  <= 15 ) {
			GPIOA->CRH &= ~((0xF) << ( (config_ptr->PIN_NUM -8) * 4));
			GPIOA->CRH |= ( LOCAL_Pin_Purpose <<( (config_ptr->PIN_NUM -8)*BASE_CRL_CRH) ) ;
		}
		else {
			STATE = INVALID_INPUT ;
		}
		break;

	case GPIO_B :
		if (config_ptr->PIN_NUM  < 8 ){
			GPIOB->CRL &= ~((0xF) << ( config_ptr->PIN_NUM  * BASE_CRL_CRH));
			GPIOB->CRL |= ( LOCAL_Pin_Purpose << (config_ptr->PIN_NUM *BASE_CRL_CRH) ) ;
		}
		else if (config_ptr->PIN_NUM  >= 8  && config_ptr->PIN_NUM  <= 15 ) {
			GPIOB->CRH &= ~((0xF) << ( (config_ptr->PIN_NUM -8) * 4));
			GPIOB->CRH |= ( LOCAL_Pin_Purpose <<( (config_ptr->PIN_NUM -8)*BASE_CRL_CRH) ) ;
		}
		else {
			STATE = INVALID_INPUT ;
		}
		break;

	case GPIO_C :
		if (config_ptr->PIN_NUM  < 8 ){
			GPIOC->CRL &= ~((0xF) << ( (config_ptr->PIN_NUM) * BASE_CRL_CRH));
			GPIOC->CRL |= ( LOCAL_Pin_Purpose << (config_ptr->PIN_NUM *BASE_CRL_CRH) ) ;
		}
		else if (config_ptr->PIN_NUM  >= 8  && config_ptr->PIN_NUM  <= 15 ) {
			GPIOC->CRH &= ~((0xF) << ( (config_ptr->PIN_NUM -8) * BASE_CRL_CRH));
			GPIOC->CRH |= ( LOCAL_Pin_Purpose <<( (config_ptr->PIN_NUM -8)*BASE_CRL_CRH) ) ;
		}
		else {
			STATE = INVALID_INPUT ;
		}
		break;

	case GPIO_D :
		if (config_ptr->PIN_NUM  < 8 ){
			GPIOD->CRL &= ~((0xF) << ( config_ptr->PIN_NUM * BASE_CRL_CRH));
			GPIOD->CRL |= ( LOCAL_Pin_Purpose << (config_ptr->PIN_NUM *BASE_CRL_CRH) ) ;
		}
		else if (config_ptr->PIN_NUM  >= 8  && config_ptr->PIN_NUM  <= 15 ) {
			GPIOD->CRH &= ~((0xF) << ( (config_ptr->PIN_NUM -8) * BASE_CRL_CRH));
			GPIOD->CRH |= ( LOCAL_Pin_Purpose <<( (config_ptr->PIN_NUM -8)*BASE_CRL_CRH) ) ;
		}
		else {
			STATE = INVALID_INPUT ;
		}
		break;
	default :
		STATE = INVALID_INPUT ;
	}
	return STATE ;
}

/*
  Input  : void
  output : void
  description :To determine the value of pin
*/
Std_ReturnType GPIOX_VidSetPinValue (const PIN_CONFIGURATION* config_ptr, u8 Copy_Pin_Value )
{
		/**/
	Std_ReturnType STATE = OK ;

	/* check on coming pointer */
	if (NULL == config_ptr){
		STATE = NULL_PTR ;
		return STATE ;
	}


	switch (config_ptr->GPIO_PORT)
	{
	case GPIO_A :
		if (Copy_Pin_Value == HIGH){
			GPIOA->BSRR = ( 1 << (config_ptr->PIN_NUM ) ) ;
		}
		else if (Copy_Pin_Value == LOW){
			GPIOA->BRR  = ( 1 << (config_ptr->PIN_NUM ) ) ;
		}
		else {
			STATE = INVALID_INPUT ;
		}
		break;

	case GPIO_B :
		if (Copy_Pin_Value == HIGH){
			GPIOB->BSRR = ( 1 << ((config_ptr->PIN_NUM ) ) ) ;
		}
		else if (Copy_Pin_Value == LOW){
			GPIOB->BRR  = ( 1 << (config_ptr->PIN_NUM ) ) ;
		}
		else {
			STATE = INVALID_INPUT ;
		}
		break;

	case GPIO_C :
		if (Copy_Pin_Value == HIGH){
			GPIOC->BSRR = ( 1 << ((config_ptr->PIN_NUM ) ) ) ;
		}
		else if (Copy_Pin_Value == LOW){
			GPIOC->BRR  = ( 1 << (config_ptr->PIN_NUM ) ) ;
		}
		else {
			STATE = INVALID_INPUT ;
		}
		break;

	case GPIO_D :
		if (Copy_Pin_Value == HIGH){
			GPIOD->BSRR = ( 1 << ((config_ptr->PIN_NUM ) ) ) ;
		}
		else if (Copy_Pin_Value == LOW){
			GPIOD->BRR  = ( 1 << (config_ptr->PIN_NUM ) ) ;
		}
		else {
			STATE = INVALID_INPUT ;
		}
		break;
	default :
		STATE = INVALID_INPUT ;
	}
	return STATE ;
}

/*
  Input  : void
  output : void
  description : To toggle pin value
*/
Std_ReturnType GPIOX_VidTogglePinValue       (const PIN_CONFIGURATION* config_ptr, u64 *Copy_Delay_Time )
{
	/**/
	Std_ReturnType STATE = OK ;

	/* check on coming pointer */
	if (NULL == config_ptr){
		STATE = NULL_PTR ;
		return STATE ;
	}

	switch (config_ptr->GPIO_PORT)
	{
	case GPIO_A :
		GPIOA->BSRR = ( 1 << ((config_ptr->PIN_NUM ) ) ) ;
		for(u32 i = 0 ; i < *Copy_Delay_Time ; i++ );
		GPIOA->BRR  = ( 1 << (config_ptr->PIN_NUM ) ) ;
		for(u32 i = 0 ; i < *Copy_Delay_Time ; i++ );
		break;

	case GPIO_B :
		GPIOB->BSRR = ( 1 << ((config_ptr->PIN_NUM ) ) ) ;
		for(u32 i = 0 ; i < *Copy_Delay_Time ; i++ );
		GPIOB->BRR  = ( 1 << (config_ptr->PIN_NUM ) ) ;
		for(u32 i = 0 ; i < *Copy_Delay_Time ; i++ );
		break;

	case GPIO_C :
		GPIOC->BSRR = ( 1 << ((config_ptr->PIN_NUM ) ) ) ;
		for(u32 i = 0 ; i < *Copy_Delay_Time ; i++ );
		GPIOC->BRR  = ( 1 << (config_ptr->PIN_NUM ) ) ;
		for(u32 i = 0 ; i < *Copy_Delay_Time ; i++ );
		break;

	case GPIO_D :
		GPIOD->BSRR = ( 1 << ((config_ptr->PIN_NUM ) ) ) ;
		for(u32 i = 0 ; i < *Copy_Delay_Time ; i++ );
		GPIOD->BRR  = ( 1 << (config_ptr->PIN_NUM ) ) ;
		for(u32 i = 0 ; i < *Copy_Delay_Time ; i++ );
		break;
	default :
		STATE = INVALID_INPUT ;
	}
	return STATE ;
}

/*
  Input  : u8 , u8
  output : u8
  description : To get pin value
*/
u8   GPIOX_U8GetPinValue           (const PIN_CONFIGURATION* config_ptr , Std_ReturnType* Copy_State)
{
	/**/
	*Copy_State = OK ;

	/* check on coming pointer */
	if (NULL == config_ptr){
		*Copy_State = NULL_PTR ;
		return *Copy_State ;
	}

	switch (config_ptr->GPIO_PORT)
	{
	case GPIO_A :
		return ( (GPIOA->IDR>>(config_ptr->PIN_NUM )) & HIGH ) ;
		break;

	case GPIO_B :
		return ( (GPIOB->IDR>>(config_ptr->PIN_NUM )) & HIGH ) ;
		break;

	case GPIO_C :
		return ( (GPIOC->IDR>>(config_ptr->PIN_NUM )) & HIGH ) ;
		break;

	case GPIO_D :
		return ( (GPIOD->IDR>>(config_ptr->PIN_NUM )) & HIGH ) ;
		break;
	default :
		*Copy_State = INVALID_INPUT ;
	}
	return *Copy_State ;
}

/*
  Input  : u8 , u8
  output : void
  description :
*/
Std_ReturnType GPIOX_VidSetPortDirectionLow  (u8 Copy_GPIOX , u8 Copy_Port_Purpose )
{
	Std_ReturnType STATE = OK ;

	switch (Copy_GPIOX)
	{
	case GPIO_A :
		GPIOA->CRL &= ~((0xFFFFFFFF));
		GPIOA->CRL |= Copy_Port_Purpose ;
		break;

	case GPIO_B :
		GPIOB->CRL &= ~((0xFFFFFFFF));
		GPIOB->CRL |= Copy_Port_Purpose ;
		break;

	case GPIO_C :
		GPIOC->CRL &= ~((0xFFFFFFFF));
		GPIOC->CRL |= Copy_Port_Purpose ;
		break;

	case GPIO_D :
		GPIOD->CRL &= ~((0xFFFFFFFF));
		GPIOD->CRL |= Copy_Port_Purpose ;
		break;
	default :
		STATE = INVALID_INPUT ;
	}
	return STATE ;
}

/*
  Input  : u8 , u8
  output : void
  description :
*/
Std_ReturnType GPIOX_VidSetPortDirectionHigh (u8 Copy_GPIOX , u8 Copy_Port_Purpose )
{
	Std_ReturnType STATE = OK ;

	switch (Copy_GPIOX)
	{
	case GPIO_A :
		GPIOA->CRH &= ~((0xFFFFFFFF));
		GPIOA->CRH = Copy_Port_Purpose ;
		break;

	case GPIO_B :
		GPIOB->CRH &= ~((0xFFFFFFFF));
		GPIOB->CRH = Copy_Port_Purpose ;
		break;

	case GPIO_C :
		GPIOC->CRH &= ~((0xFFFFFFFF));
		GPIOC->CRH = Copy_Port_Purpose ;
		break;

	case GPIO_D :
		GPIOD->CRH &= ~((0xFFFFFFFF));
		GPIOD->CRH = Copy_Port_Purpose ;
		break;
	default :
		STATE = INVALID_INPUT ;
	}
	return STATE ;
}


/*
  Input  : u8 , u8
  output : void
  description :
*/
Std_ReturnType GPIOX_VidSetPortValue(u8 Copy_GPIOX ,u8 Copy_Port_Value ){
	Std_ReturnType STATE = OK ;
	switch (Copy_GPIOX)
	{
	case GPIO_A :
		GPIOA->BSRR = Copy_Port_Value ;
		break;

	case GPIO_B :
		GPIOA->BSRR = Copy_Port_Value ;
		break;

	case GPIO_C :
		GPIOA->BSRR = Copy_Port_Value ;
		break;

	case GPIO_D :
		GPIOA->BSRR = Copy_Port_Value ;
		break;
	default :
		STATE = INVALID_INPUT ;
	}
	return STATE ;
}

/*
  Input  : u8
  output : void
  description :
*/
Std_ReturnType GPIOX_VidLockPort   (u8 Copy_GPIOX ){
	Std_ReturnType STATE = OK ;
	/* Soon */
	return STATE ;
}

/*
  Input  : u8
  output : void
  description :
*/
Std_ReturnType GPIOX_VidResetPort(u8 Copy_GPIOX ){
	/**/
	Std_ReturnType STATE = OK ;

	switch (Copy_GPIOX)
	{
	case GPIO_A :
		GPIOA->BRR = 0x0000FFFF ;
		break;

	case GPIO_B :
		GPIOB->BRR = 0x0000FFFF ;
		break;

	case GPIO_C :
		GPIOC->BRR = 0x0000FFFF ;
		break;

	case GPIO_D :
		GPIOD->BRR = 0x0000FFFF ;
		break;
	default :
		STATE = INVALID_INPUT ;
	}
	return STATE ;
}
