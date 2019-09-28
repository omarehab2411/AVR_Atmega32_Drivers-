/*
 * TIMER1.c
 *
 *  Created on: Apr 23, 2019
 *      Author: omar ehab
 */


#include <TIMER1.h>
#include <avr/io.h>
void TIMER1_NORMALMODE_INIT(void){
TCNT1H=0x00;
TCNT1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;
TIMSK|=(1<<TOIE1);
SREG=(1<<7);
}
void TIMER1_FASTPWMMODE_INIT(char mode){
	if(mode=='A') //8bit fast pwm
	{   //TIMSK|=(1<<TOIE1);
	     //SREG=(1<<7);
		TCCR1A|=(1<<WGM10);     //setting 8bit fast pwm bits with top value 255
	     TCCR1B|=(1<<WGM12);
		TCCR1A|=(1<<COM1A1)|(1<<COM1A0);
		 DDRD|=(1<<PD5);           //in fast pwm set it in inverted mode
	}
	if(mode=='B'){TCCR1A|=(1<<WGM11);   //setting channel B in fast pwm with  top =1cr1
	//TIMSK|=(1<<TOIE1);
     //SREG=(1<<7);
	TCCR1B|=(1<<WGM12)|(1<<WGM13);
	TCCR1A|=(1<<COM1B1)|(1<<COM1B0);
	DDRD|=(1<<PD4);}
	if(mode=='C') //set both channels
	{TIMSK|=(1<<TOIE1);
    SREG=(1<<7);
		       TCCR1A|=(1<<WGM10);     //setting 8bit fast pwm bits with top value 255
			     TCCR1B|=(1<<WGM12);
				TCCR1A|=(1<<COM1A1)|(1<<COM1A0); //in fast pwm set it in inverted mode
				TCCR1A|=(1<<WGM11);   //setting channel B in fast pwm with  top =1cr1
				TCCR1B|=(1<<WGM12)|(1<<WGM13);
			 TCCR1A|=(1<<COM1B1)|(1<<COM1B0);
			 DDRD|=(1<<PD4);
			 DDRD|=(1<<PD4);
	}
}
void TIMER1_NORMALMODE_START(void){
	TCCR1B|=(1<<CS10)|(1<<CS12);   //pre-scale with 1024
}
void TIMER1_NORMALMODE_STOP(void){TCCR1B=0;}
void TIMER1_FASTPWM_START(void){TCCR1B=(1<<CS12)|(1<<CS10);}
void TIMER1_FASTPWM_STOP(void){TCCR1B=0;
TCCR1A=0;}
void TIMER1_CLEAR(void){TCNT1H=0x00;
TCNT1L=0x00;}
int TIMER1_RETURNVALUE(void){return TCNT1;
}
