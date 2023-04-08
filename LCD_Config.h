/*
 * LCD_Config.h
 *
 * Created: 2/15/2023 12:51:16 PM
 *  Author: HP2023
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


#ifndef  F_CPU
#define  F_CPU 16000000UL
#endif

#define LCD_CMD_PORT  DIO_PORTB

#define LCD_RS_PIN    PIN1
#define LCD_RW_PIN    PIN2
#define LCD_E_PIN     PIN3

#define LCD_DATA_PORT  DIO_PORTA

#define LCD_D4_PIN  PIN4
#define LCD_D5_PIN  PIN5
#define LCD_D6_PIN  PIN6
#define LCD_D7_PIN  PIN7

#define LCD_INITIAL_FUNCTION_SET       CMD_LCD_4Bit_Mode_2_Line_5X8_FONT









#endif /* LCD_CONFIG_H_ */