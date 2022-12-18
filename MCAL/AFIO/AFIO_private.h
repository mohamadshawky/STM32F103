/******************************************************************************************/
/* Author     		: Mohamed Shawky                                                      */
/* Version    		: V01                                                                 */
/* Date       		: 7 Nov 2020 												          */
/* Description		: AFIO PRIVATE											              */
/* Copyrights		: This driver is implemented within ARM-Based Microcontollers course. */
/******************************************************************************************/
#ifndef _AFIO_PRIVATE_H
#define _AFIO_PRIVATE_H

typedef struct{
	u32 EVCR;
	u32 MAPR;
	u32 EXTCR[4];
	u32 MAPR2;
}AFIO_t;

#define 	AFIO 	((volatile AFIO_t * ) 0x40010000)

/* PortMap Values */
#define		A		0
#define		B		1
#define		C		2
#define		D		3
#define		E		4
#define		F		5
#define		G	 	6

#endif