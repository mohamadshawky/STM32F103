/******************************************************************************************/
/* Author     		: Mohamed Shawky                                                      */
/* Version    		: V02                                                                 */
/* Date       		: 26 Nov 2020 												          */
/* Description		: EXTI0 PRIVATE											              */
/* Copyrights		: This driver is implemented within ARM-Based Microcontollers course. */
/******************************************************************************************/
#ifndef _EXTI0_PRIVATE_
#define _EXTI0_PRIVATE_

static void (* EXTI0_CallBack) (void) = NULL;

typedef struct{
	
	volatile	 u32     IMR;
	volatile 	 u32 	 EMR;
	volatile	 u32	 RSTR;
	volatile 	 u32 	 FTSR;
	volatile 	 u32 	 SWIER;
	volatile 	 u32 	 PR;
	
}EXTI_t;

#define EXTI	((volatile EXTI_t * )	0x40010400)	

#endif
