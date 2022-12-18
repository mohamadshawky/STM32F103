/******************************************************************************************/
/* Author     		: Mohamed Shawky                                                      */
/* Version    		: V01                                                                 */
/* Date       		: 23 Nov 2020 												          */
/* Description		: STK INTERFACE											              */
/* Copyrights		: This driver is implemented within ARM-Based Microcontollers course. */
/******************************************************************************************/
#ifndef _STK_INTERFACE_H
#define _STK_INTERFACE_H

void MSTK_voidInit				  (void										 );
void MSTK_voidSetBusyWait		  (u32 Copy_u32Ticks						 );
void MSTK_voidSetIntervalSingle	  (u32 Copy_u32Ticks, void (*Copy_ptr) (void));
void MSTK_voidSetIntervalPeriodic (u32 Copy_u32Ticks, void (*Copy_ptr) (void));
void MSTK_voidStopInterval		  (void										 );
u32  MSTK_u32GetElapsedTime		  (void										 );
u32  MSTK_u32GetRemainingTime     (void										 );

#endif
