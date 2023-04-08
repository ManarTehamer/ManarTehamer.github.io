/*
 * main.c
 *
 * Created: 2/15/2023 12:24:59 PM
 *  Author: HP2023
 */ 
#define F_CPU 16000000UL
#include "MCAL/DIO_Interface.h"
#include <util/delay.h>
#include "avr/interrupt.h"
#include "HAL/LCD/LCD_Interface.h"
#include "MCAL/TIMERS/TIMERS_Interface.h"
#include "MCAL/INT/INT_Interface.h"

#include "BIT_MATHS.h"
#include "STD_TYPES.h"


void PWM_init()
{
	/*set Phase correct PWM mode with non-inverted output*/
	TCCR0 = (1<<WGM00) | (1<<COM01) | (1<<CS00);
	DDRB|=(1<<PB3);	/*set OC0 pin as output*/
}


int main ()
{
	unsigned char duty;
	
	PWM_init();
	LCD_init();
	while (1)
	{
		for(duty=0; duty<255; duty++)
		{
			OCR0=duty;			/*increase the LED light intensity*/
			_delay_ms(8);
		}
		for(duty=255; duty>1; duty--)
		{
			OCR0=duty;			/*decrease the LED light intensity*/
			_delay_ms(8);
		}
		LCD_Write_CMD(duty);
	}
}
