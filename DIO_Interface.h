/*
 * DIO_Interface.h
 *
 * Created: 2/15/2023 1:09:07 PM
 *  Author: HP2023
 */ 


#ifndef  DIO_INTERFACE_H_
#define  DIO_INTERFACE_H_

#include "../BIT_MATHS.h"
#include "../STD_TYPES.h"
#include "DIO_Private.h"

/*this macros used for the function SET_PORT_DIR  */
#define Bit0  1    //1<<0
#define Bit1  2    //1<<1
#define Bit2  4	  //1<<2
#define Bit3  8	  //1<<3
#define Bit4  (1<<4)
#define Bit5  (1<<5)
#define Bit6  (1<<6)
#define Bit7  (1<<7)
#define ALL   0xFF
#define Most_4Bits    0xF0
#define Least_4Bits   0x0F



typedef enum {INPUT,OUTPUT,INPUT_PULLUP} DIR_TYPE;

typedef enum {LOW,HIGH} IO_TYPE;

typedef enum {DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}PORT_TYPE;


typedef enum{ PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7
}PIN_TYPE;


void DIO_SetPinDir(PORT_TYPE ,PIN_TYPE , DIR_TYPE );
void DIO_SetPinVal(PORT_TYPE ,PIN_TYPE , IO_TYPE );


void DIO_SetPortDir(PORT_TYPE ,u8 BitsValue ,DIR_TYPE );
void DIO_SetPortVal(PORT_TYPE ,u8 BitsValue ,IO_TYPE  );

IO_TYPE DIO_GetPinVal(PORT_TYPE ,PIN_TYPE );


void DIO_TogglePinValue(PORT_TYPE port ,PIN_TYPE pin);


#endif /* DIO_INTERFACE_H_ */