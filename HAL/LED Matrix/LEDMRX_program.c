/******************************************************************************************/
/* Author     		: Mohamed Shawky                                                      */
/* Version    		: V01                                                                 */
/* Date       		: 27 Nov 2020 												          */
/* Description		: LEDMRX PROGRAM											          */
/* Copyrights		: This driver is implemented within ARM-Based Microcontollers course. */
/******************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_config.h"
#include "LEDMRX_private.h"

void HLEDMRX_voidInit(void){
	
	MGPIO_voidSetPinDirection(LEDMRX_ROW0_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW1_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW2_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW3_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW4_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW5_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW6_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW7_PIN, OUTPUT_SPEED_2MHZ_PP);
	
	MGPIO_voidSetPinDirection(LEDMRX_COL0_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL1_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL2_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL3_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL4_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL5_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL6_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL7_PIN, OUTPUT_SPEED_2MHZ_PP);
}

void HLEDMRX_voidDisplay(u8 *Copy_u8Data){
	
	while(1){
	
	/* Column 0 */
	DisableALLCols();						
	SetRowValues(Copy_u8Data[0]);
	MGPIO_voidSetPinValue(LEDMRX_COL0_PIN, LOW);
	MSTK_voidSetBusyWait(2500);				
		
	/* Column 1 */
	DisableALLCols();						
	SetRowValues(Copy_u8Data[1]);
	MGPIO_voidSetPinValue(LEDMRX_COL1_PIN, LOW);
	MSTK_voidSetBusyWait(2500);				
	
	/* Column 2 */
	DisableALLCols();						
	SetRowValues(Copy_u8Data[2]);
	MGPIO_voidSetPinValue(LEDMRX_COL2_PIN, LOW);
	MSTK_voidSetBusyWait(2500);				

	/* Column 3 */
	DisableALLCols();						
	SetRowValues(Copy_u8Data[3]);
	MGPIO_voidSetPinValue(LEDMRX_COL3_PIN, LOW);
	MSTK_voidSetBusyWait(2500);	

	/* Column 4 */
	DisableALLCols();						
	SetRowValues(Copy_u8Data[4]);
	MGPIO_voidSetPinValue(LEDMRX_COL4_PIN, LOW);
	MSTK_voidSetBusyWait(2500);			
	
	/* Column 5 */
	DisableALLCols();						
	SetRowValues(Copy_u8Data[5]);
	MGPIO_voidSetPinValue(LEDMRX_COL5_PIN, LOW);
	MSTK_voidSetBusyWait(2500);		

	/* Column 6 */
	DisableALLCols();						
	SetRowValues(Copy_u8Data[6]);
	MGPIO_voidSetPinValue(LEDMRX_COL6_PIN, LOW);
	MSTK_voidSetBusyWait(2500);			

	/* Column 7 */
	DisableALLCols();						
	SetRowValues(Copy_u8Data[7]);
	MGPIO_voidSetPinValue(LEDMRX_COL7_PIN, LOW);
	MSTK_voidSetBusyWait(2500);	
	}	
}
static void DisableALLCols(void){
	MGPIO_voidSetPinValue(LEDMRX_COL0_PIN, HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL1_PIN, HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL2_PIN, HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL3_PIN, HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL4_PIN, HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL5_PIN, HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL6_PIN, HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL7_PIN, HIGH);
}
	
static void SetRowValues(u8 Copy_u8Value){
	
	u8 Local_u8BIT; 
		
	Local_u8BIT = GET_BIT(Copy_u8Value,0);
	MGPIO_voidSetPinValue(LEDMRX_ROW0_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,1);
	MGPIO_voidSetPinValue(LEDMRX_ROW1_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,2);
	MGPIO_voidSetPinValue(LEDMRX_ROW2_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,3);
	MGPIO_voidSetPinValue(LEDMRX_ROW3_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,4);
	MGPIO_voidSetPinValue(LEDMRX_ROW4_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,5);
	MGPIO_voidSetPinValue(LEDMRX_ROW5_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,6);
	MGPIO_voidSetPinValue(LEDMRX_ROW6_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,7);
	MGPIO_voidSetPinValue(LEDMRX_ROW7_PIN, Local_u8BIT);
	

}