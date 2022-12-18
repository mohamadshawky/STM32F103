/******************************************************************************************/
/* Author     		: Mohamed Shawky                                                      */
/* Version    		: V02                                                                 */
/* Date       		: 26 Nov 2020 												          */
/* Description		: EXTI0 INTERFACE											          */
/* Copyrights		: This driver is implemented within ARM-Based Microcontollers course. */
/******************************************************************************************/
#ifndef _EXTI0_INTERFACE_
#define	_EXTI0_INTERFACE_

void MEXTI_voidInit           (void										  );
void MEXTI_voidSetSignalLatch (u8 Copy_u8EXTILine, u8 Copy_u8EXTISenseMode);
void MEXTI_voidEnableEXTI	  (u8 Copy_u8EXTILine						  );
void MEXTI_voidDisableEXTI    (u8 Copy_u8EXTILine						  );
void MEXTI_voidSoftwareTrigger(u8 Copy_u8EXTILine						  );
void MEXTI_voidSetCallBack    (void (*ptr) void							  );	//takes pointer to function

#endif
