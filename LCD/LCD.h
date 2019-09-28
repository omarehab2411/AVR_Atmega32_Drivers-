/*
 * LCD.h
 *
 *  Created on: Sep 17, 2018
 *      Author: omar ehab
 */

#ifndef LCD_H_
#define LCD_H_

#include<avr/io.h>
#include<stdlib.h>
#include <util/delay.h>

#define RS PA3

#define EN PD6

#define LCD_PORT PORTB

#define LCD_PORT_RS PORTA

#define LCD_PORT_EN PORTD

#define LCD_PORT_DIR_RS DDRA

#define LCD_PORT_DI_EN DDRD

#define LCD_PORT_DIR DDRB


#define LCD_CLEAR (0x01)
#define LCD_RETURNHOME (0x02)
#define  LCD_MODE (4)
#define LCD_DISPLAY_CURSOR_ON (0x0E)
#define LCD_DISPLAY_CURSOR_0FF (0x0C)
#define LCD_4BIT_2LINE (0x28)
#define LCD_8BIT_2LINE (0x38)
#define LCD_CURSOR_SET (0x80)


void LCD_INIT(void);
void LCD_SEND_COMMAND (char command);
void LCD_SEND_CHARACHTER (char charachter);
void LCD_SEND_STRING (char *string);
void LCD_NAVIGATE ( char row, char columns);
void LCD_NAVIGATE_SEND_STRING (char row, char columns,char * string);
void LCD_SET_CUSTOM (char* pattern,unsigned char location);
void LCD_INT2STRING (int integer,char *string);
void LCD_RESET (void);


#endif /* LCD_H_ */
