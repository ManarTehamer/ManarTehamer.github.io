/*
 * LCD_Prog.c
 *
 * Created: 2/15/2023 1:15:03 PM
 *  Author: HP2023
 */ 



#include "LCD_interface.h"

void LCD_init(){
	DIO_SetPinDir(LCD_CMD_PORT,LCD_RS_PIN,OUTPUT);
	DIO_SetPinDir(LCD_CMD_PORT,LCD_RW_PIN,OUTPUT);
	DIO_SetPinDir(LCD_CMD_PORT,LCD_E_PIN,OUTPUT);
	
	DIO_SetPinDir(LCD_DATA_PORT,LCD_D4_PIN,OUTPUT);
	DIO_SetPinDir(LCD_DATA_PORT,LCD_D5_PIN,OUTPUT);
	DIO_SetPinDir(LCD_DATA_PORT,LCD_D6_PIN,OUTPUT);
	DIO_SetPinDir(LCD_DATA_PORT,LCD_D7_PIN,OUTPUT);
	
	_delay_ms(15);
	LCD_Write_CMD(0x33);
	_delay_ms(1);
	LCD_Write_CMD(0x32);
	_delay_ms(1);
	LCD_Write_CMD(LCD_INITIAL_FUNCTION_SET);
	_delay_ms(1);
	LCD_Write_CMD(CMD_Display_ON_Cursor_Blink_OFF);
	_delay_ms(1);
	LCD_Write_CMD(CMD_Clear_Display);
	_delay_ms(2);
	LCD_Write_CMD(CMD_Return_Home);
	_delay_ms(2);
	LCD_Write_CMD(CMD_Shift_Cursor_Right_Per_Read_Write);
	_delay_ms(1);
	
	
	
}
void LCD_Write_CMD(u8 CMD){
	
	
	DIO_SetPinVal(LCD_CMD_PORT,LCD_RS_PIN,LOW);	 //SELECT INSTRUCTION REGISTER
	DIO_SetPinVal(LCD_CMD_PORT,LCD_RW_PIN,LOW);	 // SELECT WRITING OPERATION
	DIO_SetPinVal(LCD_CMD_PORT,LCD_E_PIN,LOW);	 //INITIAL VALUE OF ENABLE PIN
	_delay_ms(1);
	DIO_SetPinVal(LCD_CMD_PORT,LCD_E_PIN,HIGH);	 // SET E PIN TO HIGH TO  START WRITING DATA
	
	//SELECT PORT ACCORDING TO CONFIG PARAMETER AT LCD_CONFIG.H FILE
	#if (LCD_DATA_PORT== DIO_PORTA)
	PORTA = (CMD & 0xF0) | (PORTA & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTB)
	PORTB = (CMD & 0xF0) | (PORTB & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTC)
	PORTC = (CMD & 0xF0) | (PORTC & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTD)
	PORTD = (CMD & 0xF0) | (PORTD & 0x0F) ;
	
	#endif
	// MAKING A FALING EADGE AT E PIN TO TRIGER MPU TO GET DATA FROM DATA PORT
	DIO_SetPinVal(LCD_CMD_PORT,LCD_E_PIN,LOW);

	_delay_ms(2);
	
	DIO_SetPinVal(LCD_CMD_PORT,LCD_E_PIN,HIGH);
	
	#if (LCD_DATA_PORT== DIO_PORTA)
	PORTA = (CMD <<4) | (PORTA & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTB)
	PORTB = (CMD <<4) | (PORTB & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTC)
	PORTC = (CMD <<4) | (PORTC & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTD)
	PORTD = (CMD <<4) | (PORTD & 0x0F) ;
	
	#endif
	DIO_SetPinVal(LCD_CMD_PORT,LCD_E_PIN,LOW);
	
	_delay_ms(1);
	
	
	
	
	
	
	
}
void LCD_Write_CHAR(u8 CHR){
	
	
	
	DIO_SetPinVal(LCD_CMD_PORT,LCD_RS_PIN,HIGH);	// SELECT DATA REG
	DIO_SetPinVal(LCD_CMD_PORT,LCD_RW_PIN,LOW);
	DIO_SetPinVal(LCD_CMD_PORT,LCD_E_PIN,LOW);
	_delay_ms(1);
	DIO_SetPinVal(LCD_CMD_PORT,LCD_E_PIN,HIGH);
	
	#if (LCD_DATA_PORT== DIO_PORTA)
	PORTA = (CHR & 0xF0) | (PORTA & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTB)
	PORTB = (CHR & 0xF0) | (PORTB & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTC)
	PORTC = (CHR & 0xF0) | (PORTC & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTD)
	PORTD = (CHR & 0xF0) | (PORTD & 0x0F) ;
	
	#endif
	DIO_SetPinVal(LCD_CMD_PORT,LCD_E_PIN,LOW);

	_delay_ms(2);
	
	DIO_SetPinVal(LCD_CMD_PORT,LCD_E_PIN,HIGH);
	
	#if (LCD_DATA_PORT== DIO_PORTA)
	PORTA = (CHR <<4) | (PORTA & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTB)
	PORTB = (CHR <<4) | (PORTB & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTC)
	PORTC = (CHR <<4) | (PORTC & 0x0F) ;
	
	#elif (LCD_DATA_PORT== DIO_PORTD)
	PORTD = (CHR <<4) | (PORTD & 0x0F) ;
	
	#endif
	DIO_SetPinVal(LCD_CMD_PORT,LCD_E_PIN,LOW);
	
	_delay_ms(1);
	
	
	
	
	
}




void LCD_GOTO( u8 row, u8 col){
	
	
	if(row==0)
	LCD_Write_CMD   (   LCD_Line1_1stAddress + col );
	else if (row==1)
	LCD_Write_CMD   (   LCD_Line2_1stAddress + col  );
	
	
	
	
	
}



void  LCD_Write_STR(const u8 * str){
	
	while(*str != '\0'){
		
		LCD_Write_CHAR(*str);
		str++;
		
		
	}
	
	
}
