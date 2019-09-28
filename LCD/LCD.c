/*
 * LCD.C
 *
 *  Created on: Sep 17, 2018
 *      Author: omar ehab
 */




#include "LCD.h"

void LCD_INIT(void)
{LCD_PORT_DIR_RS|=(1<<RS);
LCD_PORT_DI_EN |=(1<<EN);
//4-bit mode
LCD_PORT_DIR|=0x0F;
LCD_SEND_COMMAND(LCD_RETURNHOME);
LCD_SEND_COMMAND(LCD_4BIT_2LINE);
_delay_ms(1);
LCD_SEND_COMMAND(LCD_CLEAR);
LCD_SEND_COMMAND(0x0C  );

	}
void LCD_SEND_COMMAND (char command)
{//4 bit mode

	LCD_PORT_RS&=~(1<<RS);
_delay_ms(1);
LCD_PORT_EN|=(1<<EN);
_delay_ms(1);
//send high nibble

LCD_PORT&=(0xF0);
LCD_PORT=((command>>4)&(0x0F));
LCD_PORT_EN&=~(1<<EN);
_delay_ms(1);

LCD_PORT_RS&=~(1<<RS);
LCD_PORT_EN|=(1<<EN);
_delay_ms(1);

//send lower nibble
LCD_PORT&=0xF0;
LCD_PORT=(command&0x0F);
LCD_PORT_EN&=~(1<<EN);
_delay_ms(1);

	}
void LCD_SEND_CHARACHTER (char charachter)
{LCD_PORT_RS|=(1<<RS);
_delay_ms(1);
LCD_PORT_EN|=(1<<EN);
_delay_ms(1);

//4-bit mode high nibble
LCD_PORT&=0XF0;
LCD_PORT=((charachter>>4)&(0x0F));
LCD_PORT_EN&=~(1<<EN);
_delay_ms(1);

LCD_PORT_RS|=(1<<RS);
LCD_PORT_EN|=(1<<EN);
_delay_ms(1);


//4bit low nibble
LCD_PORT&=0XF0;
LCD_PORT=(charachter&0x0F);
LCD_PORT_EN&=~(1<<EN);
_delay_ms(1);

	}

void LCD_SEND_STRING (char *string)
{unsigned char index=0;
while(string[index] !='\0')
{LCD_SEND_CHARACHTER (string[index]);
_delay_ms(1);
index++;
}

	}

void LCD_RESET (void)
{
	LCD_SEND_COMMAND(LCD_CLEAR);
}

void LCD_NAVIGATE (char row, char Column)
{unsigned char address=0;
switch (row)
{
case 0:address =(Column);
break;
case 1:address =(Column+0x40);break;
case 2:address =(Column+0x10);break;
case 3:address =(Column+0x50);break;
}


LCD_SEND_COMMAND(address|(LCD_CURSOR_SET));

}



void LCD_NAVIGATE_SEND_STRING (char row, char columns,char * string)
{
	LCD_NAVIGATE (row,columns);
	LCD_SEND_STRING (string);

	}
void LCD_SET_CUSTOM (char* pattern,unsigned char location)
{
LCD_SEND_COMMAND(0x40+(location*8) );
_delay_ms(1);
for(int i=0;i<8;i++)
{LCD_SEND_CHARACHTER(pattern[i]);
_delay_ms(1);

}
	}

void LCD_INT2STRING (int integer,char *string)
{
itoa(integer,string,10);
}



