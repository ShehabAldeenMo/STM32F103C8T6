/*
*@file       NVIC_Prg.c
*@version    1.0.0
*@brief      MCAL Direct meomry access
*@details    It contains the private address and defines that used in DMA_Prg.c
*@author     Shehab aldeen mohammed abdalah
*/

#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

typedef struct {
	volatile uint32 ISR;
	volatile uint32 IFCR;
	volatile uint32 CCR;
	volatile uint32 CNDTR;
	volatile uint32 CPAR;
	volatile uint32 CMAR;
}DMA_REG;

#define DMA_CH1_BASE           ((DMA_REG *)  (0x40020000))
#define DMA_CH2_BASE           ((DMA_REG *)  (0x4002001C))
#define DMA_CH3_BASE           ((DMA_REG *)  (0x40020030))
#define DMA_CH4_BASE           ((DMA_REG *)  (0x40020044))
#define DMA_CH5_BASE           ((DMA_REG *)  (0x40020058))
#define DMA_CH6_BASE           ((DMA_REG *)  (0x4002006C))
#define DMA_CH7_BASE           ((DMA_REG *)  (0x40020080))

#define ISR_REG_BASE    4

void DMA_SetAddress_Help(DMA_REG *Copy_DMA_Base, void *Copy_pBuffer,
		void *Copy_pPeripheral, uint16 Copy_NumOfElemnts, uint8 Copy_Size);

#endif /* DMA_PRIVATE_H_ */
