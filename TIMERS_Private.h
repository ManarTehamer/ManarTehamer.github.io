/*
 * TIMERS_Private.h
 *
 * Created: 2/15/2023 2:39:36 PM
 *  Author: HP2023
 */ 


#ifndef TIMERS_PRIVATE_H_
#define TIMERS_PRIVATE_H_

#include "../../STD_TYPES.h"

//-----TIMER0 REG ADD--------
#define  SREG  (*((volatile u8 *)(0x5F)))	  //i-bit
#define  TCCR0 (*((volatile u8 *)(0x53)))	  // WGM00/01  CS00/01/02
#define  TCNT0 (*((volatile u8 *)(0x52)))	  // counting register
#define  OCR0  (*((volatile u8 *)(0x5C)))	  // Comparing register
#define  TIMSK (*((volatile u8 *)(0x59)))	  // interrupt enable  for OVF,CTC

//-----TCCR0-------------
#define WGM00  6
#define WGM01  3
#define CS02   2
#define CS01   1
#define CS00   0
//---------TIMSK--------------
#define OCIE0 1
#define TOIE0  0




#endif /* TIMERS_PRIVATE_H_ */