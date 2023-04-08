/*
 * LCD_Interface.h
 *
 * Created: 2/15/2023 1:15:46 PM
 *  Author: HP2023
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
#include "../../MCAL/DIO_Interface.h"
#include "LCD_Config.h"
#include "LCD_Private.h"
#define F_CPU 16000000UL
#include "util/delay.h"



void LCD_init(void);
void LCD_Write_CMD(u8 CMD);
void LCD_Write_CHAR(u8 CHAR);
void LCD_GOTO( u8 row, u8 col);

void  LCD_Write_STR(const u8* str);



#endif /* LCD_INTERFACE_H_ */