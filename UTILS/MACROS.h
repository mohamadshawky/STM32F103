/*
 * MACROS.h
 *
 *  Created on: Oct 17, 2022
 *      Author: Mohamed
 */

#ifndef UTILS_MACROS_H_
#define UTILS_MACROS_H_

// delay (d) in milli seconds
#define ARM_DELAY(d)    \
	do{ \
	u32 i=500*d; \
	while(i--){asm("nop");} \
}while(0)

typedef enum{

	OK,
	NOK,
	OUT_OF_RANGE,
	NULL_POINTER

}ErrorStatus;

#define ARRSZ(arr)   (sizeof(arr)/sizeof(arr[0]))




#endif /* UTILS_MACROS_H_ */
