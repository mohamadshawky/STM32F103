/******************************************************************************************/
/* Author     		: Mohamed Shawky                                                      */
/* Version    		: V01                                                                 */
/* Date       		: 31 Oct 2020 												          */
/* Description		: NVIC PROGRAM									                      */
/* Copyrights		: This driver is implemented within ARM-Based Microcontollers course. */
/******************************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

#define SCB_AIRCR	   *((volatile u32 *)0xE000ED0C)

void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber) {
	if (Copy_u8IntNumber <= 31) {
		NVIC_ISR0 = (1 << Copy_u8IntNumber);
	} else if (Copy_u8IntNumber <= 59) {
		Copy_u8IntNumber -= 32;			// index form 0 to 31
		NVIC_ISR1 = (1 << Copy_u8IntNumber);
	} else {
		/* return  Error */
	}
}

void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber) {
	if (Copy_u8IntNumber <= 31) {
		NVIC_ICER0 = (1 << Copy_u8IntNumber);
	} else if (Copy_u8IntNumber <= 59) {
		Copy_u8IntNumber -= 32;
		NVIC_ICER1 = (1 << Copy_u8IntNumber);
	} else {
		/* return  Error */
	}
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber) {
	if (Copy_u8IntNumber <= 31) {
		NVIC_ISPR0 = (1 << Copy_u8IntNumber);
	} else if (Copy_u8IntNumber <= 59) {
		Copy_u8IntNumber -= 32;
		NVIC_ISPR1 = (1 << Copy_u8IntNumber);
	} else {
		/* return  Error */
	}
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber) {
	if (Copy_u8IntNumber <= 31) {
		NVIC_ICPR0 = (1 << Copy_u8IntNumber);
	} else if (Copy_u8IntNumber <= 59) {
		Copy_u8IntNumber -= 32;
		NVIC_ICPR1 = (1 << Copy_u8IntNumber);
	} else {
		/* return  Error */
	}
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber) {

	u8 Local_u8Result = 0;

	if (Copy_u8IntNumber <= 31) {

		Local_u8Result = GET_BIT(NVIC_IABR0, Copy_u8IntNumber);

	} else if (Copy_u8IntNumber <= 59) {
		Copy_u8IntNumber -= 32;
		Local_u8Result = GET_BIT(NVIC_IABR1, Copy_u8IntNumber);
	} else {
		/* return  Error */
	}
	return Local_u8Result;
}

void MNVIC_voidSetPriority(s8 Copy_s8IntID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority, u32 Copy_u32Group) {

	u8 Local_u8Priority = 0;

	/* Equation Masking for number of groups & sub at IPR */

	Local_u8Priority = Copy_u8SubPriority | (Copy_u8GroupPriority << ((Copy_u32Group - 0X5FA0300) / 256));

	/* Core Peripheral */
	if (Copy_s8IntID < 0) {

	}
	/* External Peripheral */

	if (Copy_s8IntID >= 0) {

		NVIC_IPR[Copy_s8IntID] = Local_u8Priority << 4;	//Priority Value for interrupt at four MSB

	}
	SCB_AIRCR = Copy_u32Group;	// masking number of groups & sub at SCB
}
