/*
*@file       NVIC_Prg.c
*@version    1.0.0
*@brief      MCAL Direct meomry access
*@details    It contains the private address and defines that used in DMA_Prg.c
*@author     Shehab aldeen mohammed abdalah
*/


/**
* \file DMA_Private.h
*
* \brief Contains private defines and addresses of registers for the MPU (Memory Protection Unit) driver.
*
* \section Scope
* Private
*
* \section Author
* Shehab Abdalah
*/

#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_


/**
 * \section Brief
 * Structure used in a pointer that helps access registers in the DMA peripheral.
 *
 * \section Details (Type Structure  \ Range Unapplicable  \ Resolution Unapplicable \ unit Address )
 */
typedef struct {
    /**
     * \section Brief
     * interrupt status register.
     */
	volatile uint32 ISR;
    /**
     * \section Brief
     *  interrupt flag clear register.
     */
	volatile uint32 IFCR;
    /**
     * \section Brief
     * channel x configuration register.
     */
	volatile uint32 CCR;
    /**
     * \section Brief
     * channel x number of data register.
     */
	volatile uint32 CNDTR;
    /**
     * \section Brief
     *  channel x peripheral address register .
     */
	volatile uint32 CPAR;
    /**
     * \section Brief
     * channel x memory address register.
     */
	volatile uint32 CMAR;
}DMA_REG;


/**
 * \section Brief
 * Pointer to a structure used to access registers in the DMA peripheral channel 1.
 *
 * \section Details (Type Macro  \ Range Unapplicable  \ Resolution Unapplicable \ unit Address )
 */
#define DMA_CH1_BASE           ((DMA_REG *)  (0x40020000))

/**
 * \section Brief
 * Pointer to a structure used to access registers in the DMA peripheral channel 2.
 *
 * \section Details (Type Macro  \ Range Unapplicable  \ Resolution Unapplicable \ unit Address )
 */
#define DMA_CH2_BASE           ((DMA_REG *)  (0x40020014))

/**
 * \section Brief
 * Pointer to a structure used to access registers in the DMA peripheral channel 3.
 *
 * \section Details (Type Macro  \ Range Unapplicable  \ Resolution Unapplicable \ unit Address )
 */
#define DMA_CH3_BASE           ((DMA_REG *)  (0x40020028))

/**
 * \section Brief
 * Pointer to a structure used to access registers in the DMA peripheral channel 4.
 *
 * \section Details (Type Macro  \ Range Unapplicable  \ Resolution Unapplicable \ unit Address )
 */
#define DMA_CH4_BASE           ((DMA_REG *)  (0x4002003C))

/**
 * \section Brief
 * Pointer to a structure used to access registers in the DMA peripheral channel 5.
 *
 * \section Details (Type Macro  \ Range Unapplicable  \ Resolution Unapplicable \ unit Address )
 */
#define DMA_CH5_BASE           ((DMA_REG *)  (0x40020050))

/**
 * \section Brief
 * Pointer to a structure used to access registers in the DMA peripheral channel 6.
 *
 * \section Details (Type Macro  \ Range Unapplicable  \ Resolution Unapplicable \ unit Address )
 */
#define DMA_CH6_BASE           ((DMA_REG *)  (0x40020064))

/**
 * \section Brief
 * Pointer to a structure used to access registers in the DMA peripheral channel 7.
 *
 * \section Details (Type Macro  \ Range Unapplicable  \ Resolution Unapplicable \ unit Address )
 */
#define DMA_CH7_BASE           ((DMA_REG *)  (0x40020078))

/**
 * \section Brief
 * It's consider the number of bits that separate between flags in ISR register.
 *
 * \section Details (Type Macro  \ Range Unapplicable  \ Resolution Unapplicable \ unit bits )
 */
#define ISR_REG_BASE    4

void DMA_SetAddress_Help(DMA_REG *Copy_DMA_Base, void *Copy_pBuffer,
		void *Copy_pPeripheral, uint16 Copy_NumOfElemnts, uint8 Copy_Size);

#endif /* DMA_PRIVATE_H_ */
