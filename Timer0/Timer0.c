/*
 * Timer0.c
 *
 *  Created on: Sep 11, 2018
 *      Author: omar ehab
 */



#include <avr/io.h>
#include "Timer0.h"
void Timer0_init(void)
{
TCCR0=(1<<FOC0);
TCNT0=0;
TIMSK=(1<<TOIE0);
SREG|=(1<<7);
}

void Timer0_start(void)
{
TCCR0 |= (1<<CS01);   //PRESCALED BY 8
}

void Timer0_stop(void)
{TCCR0 &=~ (1<<CS01);

}

void Timer0_clear(void)
{
TCNT0=0;
}

void Timer0_showvalue(unsigned char *Address)
{
*Address=TCNT0;
}

void Timer0_PWM_INIT(void)
{
	TCCR0|=(1<<WGM00)|(1<<WGM01)|(1<<COM00)|(1<<COM01);
	TCNT0=0;
     OCR0=0;
	DDRB|=(1<<PB3);
	//TIMSK|=(1<<TOIE0);
	//SREG|=(1<<7);
	}
void Timer0_PWM_DUTYCYCLE(int duty_cycle)
{
	OCR0=duty_cycle;

}


void Timer0_CTC_INIT(void){
TCCR0|=(1<<WGM01);
TCNT0=0;
TIMSK|=(1<<OCIE0);
SREG|=(1<<7);
}

void Timer0_CTC_VALUE(int match_value){
	OCR0=match_value;
}

void Timer0_CTC_STOP(void){
	TCCR0&=~((1<<CS01)|(1<<CS02));
}

void Timer0_COUNTERMODE_START(void)
{TCCR0 |= (1<<CS01)|(1<<CS02);
	}

