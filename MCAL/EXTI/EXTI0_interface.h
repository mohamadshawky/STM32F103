/******************************************************************************************/
/* Author     		: Mohamed Shawky                                                      */
/* Version    		: V02                                                                 */
/* Date       		: 26 Nov 2020 												          */
/* Description		: EXTI0 INTERFACE											          */
/* Copyrights		: This driver is implemented within ARM-Based Microcontollers course. */
/******************************************************************************************/
#ifndef _EXTI0_INTERFACE_
#define	_EXTI0_INTERFACE_

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

void MEXTI_voidInit           (void										  );
void MEXTI_voidSetSignalLatch (u8 Copy_u8EXTILine, u8 Copy_u8EXTISenseMode);
void MEXTI_voidEnableEXTI	  (u8 Copy_u8EXTILine						  );
void MEXTI_voidDisableEXTI    (u8 Copy_u8EXTILine						  );
void MEXTI_voidSoftwareTrigger(u8 Copy_u8EXTILine						  );
void MEXTI_voidSetCallBack    (void (*ptr) void							  );	//takes pointer to function

#endif
