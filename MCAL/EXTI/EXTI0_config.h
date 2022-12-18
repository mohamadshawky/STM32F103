/******************************************************************************************/
/* Author     		: Mohamed Shawky                                                      */
/* Version    		: V02                                                                 */
/* Date       		: 26 Nov 2020 												          */
/* Description		: EXTI0 CONFIG											              */
/* Copyrights		: This driver is implemented within ARM-Based Microcontollers course. */
/******************************************************************************************/
#ifndef _EXTI0_CONFIG_
#define _EXTI0_CONFIG_


/* Options:
		LINE0
		LINE1
		LINE2
		.
		.
		.
		LINE15
*/

#define 	EXTI_LINE 		EXTI_LINE0

/*
Options:
	FALLING_EDGE
	RISING_EDGE
	ON_CHANGE
*/
#define 	EXTI_SENSE_MODE		FALLING_EDGE

#endif