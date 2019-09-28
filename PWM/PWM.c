/*
 * PWM.c
 *
 *  Created on: Sep 12, 2018
 *      Author: omar ehab
 */



#include <avr/io.h>

void pwm_init(void)
{
TCCR0|=(1<<WGM00);
TCCR0|=(1<<WGM01);
TCCR0|=(1<<COM01);
TCCR0|=(1<<CS00);
TCNT0=0;
OCR0=0;
DDRB|=(1<<PB3);

}


void pwm_dutycycle(unsigned char duty_cycle)
{
OCR0=duty_cycle;
}
