/*
 * ADC.c
 *
 *  Created on: Sep 13, 2018
 *      Author: omar ehab
 */



#include <avr/io.h>

void ADC_init(void)
{
ADMUX=(1<<REFS0);
ADCSRA=(1<<ADEN)|(1<<ADPS1)|(1<<ADPS2);
}

short ADC_start(unsigned char Channel)
{

	Channel &= 0x07;
	ADMUX &= 0xf8;
	ADMUX |= Channel;
	ADCSRA |= (1 << ADSC);
	while((ADCSRA &(1<<ADSC)));
			return ADC;
}
