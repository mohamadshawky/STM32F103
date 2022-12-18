/******************************************************************************************/
/* Author     		: Mohamed Shawky                                                      */
/* Version    		: V01                                                                 */
/* Date       		: 23 Nov 2020 												          */
/* Description		: STK PROGRAM											              */
/* Copyrights		: This driver is implemented within ARM-Based Microcontollers course. */
/******************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

/* Define callback global variable */
void (*MSTK_Callback)(void);

/* Define variable for interval mode*/
static u8 MSTK_u8ModeofInterval;

void MSTK_voidInit(void) {
#if MSTK_CLK_SRC == MSTK_CLK_AHB
	MSTK -> CTRL = 0X00000004; /* Disable Timer + Disable SysTick Interrupt + Enable clock source AHB */
#else if MSTK_CLK_SRC == MSTK_CLK_AHB_8
	MSTK -> CTRL = 0; /* Disable Timer + Disable SysTick Interrupt + Enable clock source AHB/8 */
#else
	#warning "Invalid Configuration"
#endif
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks) {

	MSTK -> LOAD = Copy_u32Ticks;				    // Load Number of Ticks in Counter
	SET_BIT(MSTK->CTRL, 0);						    // Enable Timer
	while ( (GET_BIT(MSTK->CTRL,16)) == 0);      	// Pooling of counting flag + read the flag to clear

	CLR_BIT(MSTK -> CTRL, 0);						// Disable Timer
	/* Stop iterative busy wait */
	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;

}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr)(void)) {

	MSTK->LOAD = Copy_u32Ticks;				// Load Number of Ticks in Counter

	SET_BIT(MSTK->CTRL, 0); 					// Enable Timer

	MSTK_u8ModeofInterval = MSTK_SINGLE_INTERVAL;

	MSTK_Callback = Copy_ptr; 					// Dynamic routine execution

	SET_BIT(MSTK->CTRL, 1);					// Enable interrupt flag

}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr)(void)) {

	MSTK -> LOAD = Copy_u32Ticks;				//Load Number of Ticks in Counter

	SET_BIT(MSTK->CTRL, 0);						//Enable Timer

	MSTK_u8ModeofInterval = MSTK_PERIODIC_INTERVAL;

	MSTK_Callback = Copy_ptr;					// dynamic routine execution

	SET_BIT(MSTK->CTRL, 1);						// Enable interrupt flag
}

void MSTK_voidStopInterval(void) {

	CLR_BIT(MSTK->CTRL, 0);						//Disable Timer

	// Stop iterative busy wait
	MSTK->LOAD = 0;
	MSTK->VAL  = 0;
}

u32 MSTK_u32GetElapsedTime(void) {

	u32 Local_u32ElapsedTime;

	Local_u32ElapsedTime = MSTK->LOAD  - MSTK->VAL;

	return Local_u32ElapsedTime;
}

u32 MSTK_u32GetRemainingTime(void) {

	u32 Local_u32RemainTime;

	Local_u32RemainTime = MSTK->VAL;

	return Local_u32RemainTime;
}

void SysTick_Handler(void) {

	u8 Local_u8Temporary;

#if (MSTK_u8ModeofInterval == MSTK_SINGLE_INTERVAL)

	/* Disable STK interrupt */
	CLR_BIT(MSTK->CTRL,1);

	/* Stop Timer */
	CLR_BIT(MSTK -> CTRL, 0);
	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;

#elif
	/* Return Error */

#endif

	/* Clear interrupt flag*/
	Local_u8Temporary = GET_BIT(MSTK->CTRL, 16);

	/* Callback notification*/
	MSTK_Callback();
}

