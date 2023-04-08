/*
 * DIO_Prog.c
 *
 * Created: 2/15/2023 1:09:51 PM
 *  Author: HP2023
 */ 


#include "DIO_Interface.h"

void DIO_SetPinDir(PORT_TYPE port ,PIN_TYPE pin , DIR_TYPE dir){
	
	
	switch(port){
		case DIO_PORTA :
		
		switch(dir){
			case OUTPUT : SET_BIT(DDRA,pin); break;
			case INPUT  : CLR_BIT(DDRA,pin) ;break;
			case INPUT_PULLUP: 	  CLR_BIT(DDRA,pin); SET_BIT(PORTA,pin);break;
		}
		break;
		
		case DIO_PORTB :
		switch(dir){
			case OUTPUT : SET_BIT(DDRB,pin); break;
			case INPUT  : CLR_BIT(DDRB,pin) ;break;
			case INPUT_PULLUP: 	  CLR_BIT(DDRB,pin); SET_BIT(PORTB,pin);break;
		}
		break;
		
		
		case DIO_PORTC:
		switch(dir){
			case OUTPUT : SET_BIT(DDRC,pin); break;
			case INPUT  : CLR_BIT(DDRC,pin) ;break;
			case INPUT_PULLUP: 	  CLR_BIT(DDRC,pin); SET_BIT(PORTC,pin);break;
		}
		break;
		case DIO_PORTD:
		switch(dir){
			case OUTPUT : SET_BIT(DDRD,pin); break;
			case INPUT  : CLR_BIT(DDRD,pin) ;break;
			case INPUT_PULLUP: 	  CLR_BIT(DDRD,pin); SET_BIT(PORTD,pin);break;
		}
		break;
	}
}

void DIO_SetPinVal(PORT_TYPE port ,PIN_TYPE pin, IO_TYPE val ){
	
	
	switch(port){
		case DIO_PORTA :
		(val==HIGH)?  SET_BIT(PORTA,pin):CLR_BIT(PORTA,pin) ;
		break;
		case DIO_PORTB :
		(val==HIGH)?  SET_BIT(PORTB,pin):CLR_BIT(PORTB,pin) ;
		break;
		
		case DIO_PORTC:
		(val==HIGH)?  SET_BIT(PORTC,pin):CLR_BIT(PORTC,pin) ;
		break;
		case DIO_PORTD:
		(val==HIGH)?  SET_BIT(PORTD,pin):CLR_BIT(PORTD,pin) ;
		break;
	}
}


IO_TYPE DIO_GetPinVal(PORT_TYPE port ,PIN_TYPE pin ){
	switch(port){
		case DIO_PORTA :    return GET_BIT(PINA,pin);
		case DIO_PORTB :    return GET_BIT(PINB,pin);
		case DIO_PORTC :    return GET_BIT(PINC,pin);
		case DIO_PORTD :    return GET_BIT(PIND,pin);
		
	}
}


void DIO_SetPortDir(PORT_TYPE port ,u8 BitsValue ,DIR_TYPE dir ){
	
	switch(port){

		case DIO_PORTA :
		
		if (dir==OUTPUT){DDRA|=BitsValue; }
		
		else if(dir ==INPUT) DDRA &= (~BitsValue);
		
		else if (dir == INPUT_PULLUP){
			DDRA &= (~BitsValue);
			PORTA |=BitsValue;
			
		}

		break;
		case DIO_PORTB :
		
		if (dir==OUTPUT){DDRB|=BitsValue; }
		
		else if(dir ==INPUT) DDRB &= (~BitsValue);
		
		else if (dir == INPUT_PULLUP){
			DDRB &= (~BitsValue);
			PORTB |=BitsValue;
			
		}
		
		break;

		case DIO_PORTD :
		
		if (dir==OUTPUT){DDRD|=BitsValue; }
		
		else if(dir ==INPUT) DDRD &= (~BitsValue);
		
		else if (dir == INPUT_PULLUP){
			DDRD &= (~BitsValue);
			PORTD |=BitsValue;
			
		}

		break;
		case DIO_PORTC :
		
		if (dir==OUTPUT){DDRC|=BitsValue; }
		
		else if(dir ==INPUT) DDRC &= (~BitsValue);
		
		else if (dir == INPUT_PULLUP){
			DDRC &= (~BitsValue);
			PORTC |=BitsValue;
			
		}
		
		break;

	}
	
	
}

void DIO_SetPortVal(PORT_TYPE port ,u8 BitsValue ,IO_TYPE mode ){
	switch(port){
		case DIO_PORTA :
		(mode==HIGH) ? (PORTA|=BitsValue) : (PORTA &= (~BitsValue));
		break;
		case DIO_PORTB :
		(mode==HIGH) ? (PORTB|=BitsValue) : (PORTB &= (~BitsValue));
		break;
		case DIO_PORTD :
		(mode==HIGH) ? (PORTD|=BitsValue) : (PORTD &= (~BitsValue));
		break;
		case DIO_PORTC :
		(mode==HIGH) ? (PORTC|=BitsValue) : (PORTC &= (~BitsValue));
		break;
	}
}

