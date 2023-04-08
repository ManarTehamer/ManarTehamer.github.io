/*
 * TIMERS_Config.h
 *
 * Created: 2/15/2023 2:40:08 PM
 *  Author: HP2023
 */ 


#ifndef TIMERS_CONFIG_H_
#define TIMERS_CONFIG_H_


#define NORMAL_MODE  0
#define PWM_PHASE_CORRECT 1
#define CTC_MODE  2
#define PWM_FAST_MODE 3

#define disable   0
#define PRE_1     1
#define PRE_8     2
#define PRE_64    3
#define PRE_256   4
#define PRE_1024  5
#define CLK_FALLING_EDGE 6
#define CLK_RISING_EDGE 7



#define TIMER0_MODE  NORMAL_MODE
#define TIMER0_FREQ	  PRE_256




#endif /* TIMERS_CONFIG_H_ */