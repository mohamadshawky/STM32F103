/*
 * main.c
 *
 *  Created on: Nov 26, 2020
 *      Author: Mohamed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "EXTI0_interface.h"

void Mohamed (void)
{
	/*Pin A2 High			*/
	MGPIO_voidSetPinValue(GPIOA , PIN2 , HIGH );
	/*Delay for 1 Sec		*/ 
	MSTK_voidSetBusyWait( 1000000 );
	
	/*Pin A2 Low			*/
	MGPIO_voidSetPinValue(GPIOA , PIN2 , LOW );
	/*Delay for 1 Sec		*/ 
	MSTK_voidSetBusyWait( 1000000 );
	
}
void Shawky (void)
{
	/*Pin A2 High			*/
	MGPIO_voidSetPinValue(GPIOA , PIN3 , HIGH );
	/*Delay for 1 Sec		*/ 
	MSTK_voidSetBusyWait( 1000000 );
	
	/*Pin A2 Low			*/
	MGPIO_voidSetPinValue(GPIOA , PIN3 , LOW );
	/*Delay for 1 Sec		*/ 
	MSTK_voidSetBusyWait( 1000000 );
	
}

void main(void){
	
	RCC_voidInitSysClock(void);
		
	RCC_voidEnableClock(APB2, 0);		/* AFIO RCC */
	
	RCC_voidEnableClock(APB2, GPIOA);	/* GPIO RCC */
	
	MSTK_void_SetCallBack(Mohamed);
	
	/** GPIO Direction **/
	
	/* A0 => Input, Pull up resistor */ 
	MGPIOA_voidSetPinDirection(GPIOA, PIN0, INPUT_PULL_UP_DOWN);
	MGPIOA_voidSetPinValue(GPIOA, PIN0, HIGH);
	 
	/* A2 => Output speed 2MHZ push pull*/
	MGPIOA_voidSetPinDirection(GPIOA, PIN2, OUTPUT_SPEED_2MHZ_PP);
	
	MEXTI_voidInit();
	MEXTI_SetSignalLatch(EXTI_LIN0, FALLING_EDGE); 	

	MNVIC_voidSetPriority(6,2,0,NVIC_GROUP_2_SUB_2);
	MNVIC_voidEnableInterrupt(6);	
	
	//MNVIC_voidSetPendingflag(6);
	
	//MAFIO_voidSetEXTIConfig(LINE0, A);
	
	while (1);
	
	

	
	
}
