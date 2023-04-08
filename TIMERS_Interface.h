/*
 * TIMERS_Interface.h
 *
 * Created: 2/15/2023 2:39:07 PM
 *  Author: HP2023
 */ 


#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_

#include "../../BIT_MATHS.h"
#include "../../STD_TYPES.h"
#include "TIMERS_Config.h"
#include "TIMERS_Private.h"

void Timer0_INIT (void);
void Timer0_Start(void);
void Timer0_Stop (void);



#endif /* TIMERS_INTERFACE_H_ */