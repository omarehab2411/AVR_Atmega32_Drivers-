/*
 * SERVO_TIMER1.c
 *
 *  Created on: Apr 27, 2019
 *      Author: omar ehab
 */

#include "SERVO_TIMER1.h"

void SERVO_MOTOR_INIT(unsigned short int TOP_VALUE){
	DDRD|=(1<<PD5);
	TCCR1A|=(1<<WGM11)|(1<<COM1A1);
	TCCR1B|=(1<<WGM12)|(1<<WGM13);
	TCNT1=0;
	ICR1=TOP_VALUE;
}
void SERVO_MOTOR_START(void){
	TCCR1B|=(1<<CS12);
}
void SERVO_MOTOR_STOP(void)
{TCCR1B&=~(1<<CS12);
	}

void SERVO_MOTOR_DUTYCYCLE(unsigned short int DUTY_CYCLE)
{OCR1A=DUTY_CYCLE;
	}

