/******************************************************************************************/
/* Author     		: Mohamed Shawky                                             		  */
/* Version    		: V01                                                                 */
/* Date       		: 31 Oct 2020 											              */
/* Description		: NVIC INTERFACE					     						      */
/* Copyrights		: This driver is implemented within ARM-Based Microcontollers course. */
/******************************************************************************************/
#ifndef	_NVIC_INTERFACE_H
#define _NVIC_INTERFACE_H

#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber);
void MNVIC_voidSetPriority(s8 Copy_s8IntID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority, u32 Copy_u32Group);

#endif
