/******************************************************************************************/
/* Author     		: Mohamed Shawky                                                      */
/* Version    		: V02                                                                 */
/* Date       		: 26 Nov 2020 												          */
/* Description		: EXTI0 PRIVATE											              */
/* Copyrights		: This driver is implemented within ARM-Based Microcontollers course. */
/******************************************************************************************/
#ifndef _EXTI0_PRIVATE_
#define _EXTI0_PRIVATE_

#define NULL		(void * )	0

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

/* Sense mode options */
#define 	FALLING_EDGE	0
#define		RISING_EDGE		1
#define		ON_CHANGE		2

/* EXTI lines */
#define 	EXTI_LINE0		0 
#define 	EXTI_LINE1		1 
#define 	EXTI_LINE2		2 
#define 	EXTI_LINE3		3 
#define 	EXTI_LINE4		4 
#define 	EXTI_LINE5		5 
#define 	EXTI_LINE6		6 
#define 	EXTI_LINE7		7 
#define 	EXTI_LINE8		8 
#define 	EXTI_LINE9		9 
#define 	EXTI_LINE10		10 
#define 	EXTI_LINE11		11 
#define 	EXTI_LINE12		12 
#define 	EXTI_LINE13		13 
#define 	EXTI_LINE14		14 
#define 	EXTI_LINE15		15 


#endif