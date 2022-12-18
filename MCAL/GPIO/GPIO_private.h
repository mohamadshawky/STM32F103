/*********************************************************************************/
/* Author     		: Mohamed Shawky                                             */
/* Version    		: V01                                                        */
/* Date       		: 26 SEP 2020 												 */
/* Description		: GPIO PRIVATE										             */
/*********************************************************************************/
#ifndef _GPIO_PRIVATE_H
#define _GPIO_PRIVATE_H

#define 	GPIOA_BASE_ADDRESS		0X40010800				/* Define the boundary address of GPIOA */
#define 	GPIOB_BASE_ADDRESS		0X40010C00				/* Define the boundary address of GPIOB */
#define 	GPIOC_BASE_ADDRESS		0X40011000				/* Define the boundary address of GPIOC */

/* Register Definitions for PORTA */

#define		GPIOA_CRL 			*((u32*)(GPIOA_BASE_ADDRESS + 0x00))
#define		GPIOA_CRH 			*((u32*)(GPIOA_BASE_ADDRESS + 0x04))
#define 	GPIOA_IDR 			*((u32*)(GPIOA_BASE_ADDRESS + 0x08))
#define		GPIOA_ODR 			*((u32*)(GPIOA_BASE_ADDRESS + 0x0C))
#define		GPIOA_BSR		    *((u32*)(GPIOA_BASE_ADDRESS + 0x10))
#define		GPIOA_BRR 			*((u32*)(GPIOA_BASE_ADDRESS + 0x14))
#define		GPIOA_LCK 			*((u32*)(GPIOA_BASE_ADDRESS + 0x18))

/* Register Definitions for PORTB */

#define		GPIOB_CRL 			*((u32*)(GPIOB_BASE_ADDRESS + 0x00))
#define		GPIOB_CRH 			*((u32*)(GPIOB_BASE_ADDRESS + 0x04))
#define		GPIOB_IDR 			*((u32*)(GPIOB_BASE_ADDRESS + 0x08))
#define		GPIOB_ODR 			*((u32*)(GPIOB_BASE_ADDRESS + 0x0C))
#define		GPIOB_BSR		    *((u32*)(GPIOB_BASE_ADDRESS + 0x10))
#define		GPIOB_BRR 			*((u32*)(GPIOB_BASE_ADDRESS + 0x14))
#define		GPIOB_LCK 			*((u32*)(GPIOB_BASE_ADDRESS + 0x18))

/* Register Definitions for PORTC */

#define		GPIOC_CRL 			*((u32*)(GPIOC_BASE_ADDRESS + 0x00))
#define		GPIOC_CRH 			*((u32*)(GPIOC_BASE_ADDRESS + 0x04))
#define		GPIOC_IDR 			*((u32*)(GPIOC_BASE_ADDRESS + 0x08))
#define		GPIOC_ODR 			*((u32*)(GPIOC_BASE_ADDRESS + 0x0C))
#define		GPIOC_BSR		    *((u32*)(GPIOC_BASE_ADDRESS + 0x10))
#define		GPIOC_BRR 			*((u32*)(GPIOC_BASE_ADDRESS + 0x14))
#define		GPIOC_LCK 			*((u32*)(GPIOC_BASE_ADDRESS + 0x18))

#endif
