/*
 * INT_Interface.h
 *
 * Created: 2/15/2023 3:10:56 PM
 *  Author: HP2023
 */ 


#ifndef INT_INTERFACE_H_
#define INT_INTERFACE_H_


#include "INT_Private.h"
#include "INT_Config.h"
#include "../../BIT_MATHS.h"
#include "../../STD_TYPES.h"

#define IRQ_AT_LOW_LEVEL         0
#define IRQ_AT_ANY_LOGIC_CHANGE  1
#define IRQ_AT_FALLING_EDGE      2
#define IRQ_AT_RISING_EDGE       3

#define INT2_PIN  2
#define INT1_PIN  1
#define INT0_PIN  0


void GIE();
void GID();

void EX_INT_SET_MODE(u8 INT_PIN ,u8 IRQ);



#endif /* INT_INTERFACE_H_ */