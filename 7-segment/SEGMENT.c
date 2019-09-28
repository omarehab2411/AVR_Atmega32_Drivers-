/*
 * SEGMENT.c
 *
 *  Created on: Dec 14, 2018
 *      Author: omar ehab
 */


#include"SEGMENT.h"
#include "TIMER0.h"
#include <util/delay.h>
#include <avr/interrupt.h>




void SEGMENT_INIT(void)
{
DDRB=(1<<PB0)|(1<<PB1)|(1<<PB2)|(1<<PB3);
DDRA|=(1<<PC4);
DDRA|=(1<<PA3);
PORTA|=(1<<PA4);
PORTA|=(1<<PA3);
}
void SEGMENT_SETNUM (int num,volatile uint8_t *arr)
{int i=0;
int j=0;
	while(num)
	{arr[i]=num%10;
	i++;
	num/=10;

	}
	for(j=i;j<2;j++) arr[j]=0;
}


void SEGMENT_REFRESH(char value)
{

	TIMSK =(1<<TOIE0);		        /* Enable Timer0 overflow interrupts */
	TCNT0 = value;		                /* load TCNT0, count for 10ms*/
	TCCR0 = (1<<CS02);  /* start timer0 with /1024 prescaler*/
}


void set_brightness(int brightvalue)
{
	int brightness = brightvalue;
	while (0 < brightness)
	{
		_delay_us(1);
		--brightness;
	}
}
