/******************************************************************************************/
/* Author     		: Mohamed Shawky                                                      */
/* Version    		: V01                                                                 */
/* Date       		: 23 Nov 2020 												          */
/* Description		: STK PRIVATE											              */
/* Copyrights		: This driver is implemented within ARM-Based Microcontollers course. */
/******************************************************************************************/
#ifndef _STK_PRIVATE_H
#define _STK_PRIVATE_H

/* Clock source selection */
#define MSTK_SRC_AHB					0
#define MSTK_SRC_AHB_8					1

/* Define variable for interval mode */
#define MSTK_SINGLE_INTERVAL			0
#define MSTK_PERIODIC_INTERVAL		 	1

/* Register Definitions for SysTick */
typedef struct{
	volatile u32 CTRL	;
	volatile u32 LOAD	;
	volatile u32 VAL	;
	volatile u32 CALIB	;
}MSTK_T;

#define MSTK	((MSTK_T*)	0xE000E010)

#endif
