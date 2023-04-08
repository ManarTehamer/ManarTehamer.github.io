/*
 * INT_Prog.c
 *
 * Created: 2/15/2023 3:10:25 PM
 *  Author: HP2023
 */ 

#include "INT_Interface.h"

void GIE(){
	SET_BIT(SREG,I_BIT);
}
void GID(){
	CLR_BIT(SREG,I_BIT);
}


void EX_INT_SET_MODE(u8 INT_PIN ,u8 IRQ){
	
	
	
	switch(INT_PIN){
		
		case INT0_PIN :
		SET_BIT(GICR,INT0_EN);	 //enable interrupts of int0
		MCUCR &= 0xFC;	// clear the two bits of isc01,00
		MCUCR |= IRQ;
		
		break;
		
		case INT1_PIN :
		
		SET_BIT(GICR,INT1_EN);	//enable interrupts of int1

		MCUCR &= 0xF3;	// clear the two bits of isc11,10
		MCUCR |=IRQ<<2;
		break;
		
		case INT2_PIN :
		
		SET_BIT(GICR,INT2_EN); //enable interrupts of int2
		
		switch(IRQ){
			
			case IRQ_AT_FALLING_EDGE:
			
			CLR_BIT(MCUCSR,ISC2);
			
			break;
			
			case IRQ_AT_RISING_EDGE :
			
			SET_BIT(MCUCSR,ISC2);

			break;
			
		}
		
		break;
		
		
		
	}
}