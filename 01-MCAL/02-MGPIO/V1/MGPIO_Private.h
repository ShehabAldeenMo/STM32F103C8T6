/*
 * file            : GPIO_Private.h
 * author          : Shehab aldeen
 * brief           :
*/

#ifndef MGPIO_PRIVATE_H_
#define MGPIO_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"

#define BASE_CRL_CRH          4
#define BASE_BSRR             16



/* address */

/* GPIOX_Private.h */
typedef struct {
	u32 CRL;              /* configuration register low */
	u32 CRH;              /* configuration register High */
	u32 IDR;              /* input data register */
	u32 ODR;              /* output data register */
	u32 BSRR;             /* bit set/reset register*/
	u32 BRR;              /* bit reset register */
	u32 LCKR;             /* longer possible to modify the value of the port bit until the next reset. */
}GPIOX_REG;


/* base address */
#define GPIOA        ((volatile GPIOX_REG *)(0x40010800))
#define GPIOB        ((volatile GPIOX_REG *)(0x40010C00))
#define GPIOC        ((volatile GPIOX_REG *)(0x40011000))
#define GPIOD        ((volatile GPIOX_REG *)(0x40011400))

#endif /* MGPIO_PRIVATE_H_ */
