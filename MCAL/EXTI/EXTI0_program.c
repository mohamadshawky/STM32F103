/******************************************************************************************/
/* Author     		: Mohamed Shawky                                                      */
/* Version    		: V02                                                                 */
/* Date       		: 26 Nov 2020 												          */
/* Description		: EXTI0 PROGRAM											              */
/* Copyrights		: This driver is implemented within ARM-Based Microcontollers course. */
/******************************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "EXTI0_interface.h"
#include "EXTI0_config.h"
#include "EXTI0_private.h"

void MEXTI_voidInit(void){
	
	// for external interrupt line
	
	#if EXTI_LINE	 == EXTI_LINE0
		SET_BIT(EXTI -> IMR, EXTI_LINE0);
		
	#elif EXTI_LINE	 == EXTI_LINE1
		SET_BIT(EXTI -> IMR, EXTI_LINE1);
		
	#elif EXTI_LINE  == EXTI_LINE2
		SET_BIT(EXTI -> IMR, EXTI_LINE2 );
		
	#elif EXTI_LINE  == EXTI_LINE3
	
	#else
		#error ("Wrong External Interrupt Line!")
	
	#endif
	
	// for sense mode
	
	#if EXTI_SENSE_MODE 	== FALLING_EDGE
			SET_BIT(EXTI -> FTSR, EXTI_LINE);

	#elif EXTI_SENSE_MODE 	== RISING_EDGE
			SET_BIT(EXTI -> RTSR, EXTI_LINE);

	#elif EXTI_SENSE_MODE	== ON_CHANGE
			SET_BIT(EXTI -> FTSR, EXTI_LINE);
			SET_BIT(EXTI -> RTSR, EXTI_LINE);

	#else
		#error ("Wrong External Interrupt Sense Mode!")
	
	#endif
	
}

	// for changing sense mode, line in run time
void MEXTI_voidSetSignalLatch(u8 Copy_u8EXTILine, u8 Copy_u8EXTISenseMode){
	
	switch (Copy_u8EXTISenseMode){
		
		case FALLING_EDGE:			SET_BIT(EXTI -> FTSR, EXTI_LINE);	break;
	
		case RISING_EDGE :			SET_BIT(EXTI -> RSTR, EXTI_LINE);	break;
	
		case ON_CHANGE	 :			SET_BIT(EXTI -> FTSR, EXTI_LINE);
									SET_BIT(EXTI -> RSTR, EXTI_LINE);	break;
									
		}
		SET_BIT(EXTI -> IMR, EXTI_LINE);

	
}
void MEXTI_voidEnableEXTI(u8 Copy_u8EXTILine){
	
			SET_BIT(EXTI -> IMR, Copy_u8EXTILine);

}
void MEXTI_voidDisableEXTI(u8 Copy_u8EXTILine){
	
			CLR_BIT(EXTI -> IMR, Copy_u8EXTILine);

}
void MEXTI_voidSoftwareTrigger(u8 Copy_u8EXTILine){
	
	SET_BIT(EXTI -> SWIER, Copy_u8EXTILine);
	
}
void MEXTI_voidSetCallBack(void (*ptr) void){
	
	EXTI0_CallBack = ptr ;
	
}

void	EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
	/*	Clear pending Bit		*/
	SET_BIT(EXTI -> PR , 0);

}
