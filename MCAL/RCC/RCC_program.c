/*********************************************************************************/
/* Author    : Mohamed Shawky                                                    */
/* Version   : V01                                                               */
/* Date      : 18 SEP 2020                                                       */
/*********************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock() {
#if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
	RCC_CR   |= 0x00010000; /* Enable HSE with no Bypass */
	RCC_CFGR = 0x00000001; /* Select HSE as clock source */
#elif RCC_CLOCK_TYPE == RCC_HSE_RC
	RCC_CR   = 0X00050000; /* Enable HSE with  Bypass */
	RCC_CFGR = 0x00000001; /* Select HSE as clock source */
#elif RCC_CLOCK_TYPE == RCC_HSI
	RCC_CR   = 0x00000081; /* Enable HSI + Trimming = 0 */
	RCC_CFGR = 0x00000000; /* Select HSI as clock source */
#elif RCC_CLOCK_TYPE == RCC_PLL
	#if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
		RCC_CFGR  = 0x00000002; /* Select PLL as System Clock + HSI/2 */
		RCC_CFGR |= (RCC_PLL_MUL_VAL << 18); /* RCC Multiplication factor */
		RCC_CR   |= 0x01000081; /* Enable HSI + Trimming = 0 + PLL ON */
	#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
		RCC_CFGR  = 0x00030002; /* Select HSE as System Clock + HSE/2 */
		RCC_CFGR |= (RCC_PLL_MUL_VAL << 18); /* RCC Multiplication factor */
		RCC_CR    = 0x01010080; /* Enable HSE + Trimming = 0 + PLL ON */
	#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
		RCC_CFGR  = 0x00010002; /* Select PLL as System Clock + HSE not divided */
		RCC_CFGR |= (RCC_PLL_MUL_VAL << 18); /* RCC Multiplication factor */
		RCC_CR    = 0x01010080; /* Enable HSE + Trimming = 0 + PLL ON */
	#endif
#else
	#error "You have chosen a wrong clock type"
#endif
}

void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId) {
	if (Copy_u8PerId <= 31){
		switch (Copy_u8BusId) {
		case RCC_AHB:
			SET_BIT(RCC_AHBENR, Copy_u8PerId);
			break;
		case RCC_APB1:
			SET_BIT(RCC_APB1ENR, Copy_u8PerId);
			break;
		case RCC_APB2:
			SET_BIT(RCC_APB2ENR, Copy_u8PerId);
			break;
		}
	}

	else {
		/* Return Error */
	}

}

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId) {
	if (Copy_u8PerId <= 31) {
		switch (Copy_u8BusId) {
		case RCC_AHB:
			CLR_BIT(RCC_AHBENR, Copy_u8PerId);
			break;
		case RCC_APB1:
			CLR_BIT(RCC_APB1ENR, Copy_u8PerId);
			break;
		case RCC_APB2:
			CLR_BIT(RCC_APB2ENR, Copy_u8PerId);
			break;
		}
	}

	else {
		/* Return Error */
	}

}
