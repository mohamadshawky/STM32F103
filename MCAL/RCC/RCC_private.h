/**********************************************************************************/
/* Author     : Mohamed Shawky                                                    */
/* Version    : V01                                                               */
/* Date       : 18 SEP 2020                                                       */
/* Description: contains Registers definitions & components that are not allowed  */
/*              to use in MCAL, HAL above Layers by user. but They are used       */
/* 				by program.c													  */
/**********************************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/* Register Definitions */
#define RCC_CR         *((u32*)0x40021000)
#define RCC_CFGR       *((u32*)0x40021004)
#define RCC_CIR        *((u32*)0x40021008)
#define RCC_APB2RSTR   *((u32*)0x4002100C)
#define RCC_APB1RSTR   *((u32*)0x40021010)
#define RCC_AHBENR     *((u32*)0x40021014)
#define RCC_APB2ENR    *((u32*)0x40021018)
#define RCC_APB1ENR    *((u32*)0x4002101C)
#define RCC_BDCR       *((u32*)0x40021020)
#define RCC_CSR        *((u32*)0x40021024)

/* Clock Types */
#define RCC_HSE_CRYSTAL			0
#define RCC_HSE_RC				1		
#define RCC_HSI					2
#define RCC_PLL					3

/* PLL Options */
#define RCC_PLL_IN_HSI_DIV_2	0
#define RCC_PLL_IN_HSE_DIV_2	1
#define RCC_PLL_IN_HSE			2

/* PLL MUL factor options */
#define RCC_PLL_MUL_VAL_x_2		0
#define RCC_PLL_MUL_VAL_x_3		1
#define RCC_PLL_MUL_VAL_x_4		2
#define RCC_PLL_MUL_VAL_x_5		3
#define RCC_PLL_MUL_VAL_x_6		4
#define RCC_PLL_MUL_VAL_x_7		5
#define RCC_PLL_MUL_VAL_x_8		6
#define RCC_PLL_MUL_VAL_x_9		7
#define RCC_PLL_MUL_VAL_x_10	8
#define RCC_PLL_MUL_VAL_x_11	9
#define RCC_PLL_MUL_VAL_x_12	10
#define RCC_PLL_MUL_VAL_x_13	11
#define RCC_PLL_MUL_VAL_x_14	12
#define RCC_PLL_MUL_VAL_x_15	13
#define RCC_PLL_MUL_VAL_x_16	14
#define RCC_PLL_MUL_VAL_x_16_	15

#endif	/* RCC_PRIVATE_H */
