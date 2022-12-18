/******************************************************************************************/
/* Author     		: Mohamed Shawky                                                      */
/* Version    		: V01                                                                 */
/* Date       		: 27 Nov 2020 												          */
/* Description		: LEDMRX INTERFACE											          */
/* Copyrights		: This driver is implemented within ARM-Based Microcontollers course. */
/******************************************************************************************/
#ifndef _LEDMRX_INTERFACE_
#define _LEDMRX_INTERFACE_
	
	/* Please write pin pair Port,Pin */
#define		 LEDMRX_ROW0_PIN		GPIOA,0
#define		 LEDMRX_ROW1_PIN		GPIOA,1
#define		 LEDMRX_ROW2_PIN		GPIOA,2
#define		 LEDMRX_ROW3_PIN		GPIOA,3
#define		 LEDMRX_ROW4_PIN		GPIOA,4
#define		 LEDMRX_ROW5_PIN		GPIOA,5
#define		 LEDMRX_ROW6_PIN		GPIOA,6
#define		 LEDMRX_ROW7_PIN		GPIOA,7

#define		 LEDMRX_COL0_PIN		GPIOB,0
#define		 LEDMRX_COL1_PIN		GPIOB,1
#define		 LEDMRX_COL2_PIN		GPIOB,5
#define		 LEDMRX_COL3_PIN		GPIOB,6
#define		 LEDMRX_COL4_PIN		GPIOB,7
#define		 LEDMRX_COL5_PIN		GPIOB,8
#define		 LEDMRX_COL6_PIN		GPIOB,9
#define		 LEDMRX_COL7_PIN		GPIOB,10

void HLEDMRX_voidInit	(void			);
void HLEDMRX_voidDisplay(u8 *Copy_u8Data);

#endif