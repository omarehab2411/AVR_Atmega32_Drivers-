/*
 * TIMER1.h
 *
 *  Created on: Apr 23, 2019
 *      Author: omar ehab
 */

#ifndef TIMER1_H_
#define TIMER1_H_

#include <avr/io.h>
#include <avr/interrupt.h>


void TIMER1_NORMALMODE_INIT(void);
void TIMER1_FASTPWMMODE_INIT(char mode);
void TIMER1_NORMALMODE_START(void);
void TIMER1_NORMALMODE_STOP(void);
void TIMER1_FASTPWM_START(void);
void TIMER1_FASTPWM_STOP(void);
void TIMER1_CLEAR(void);
int TIMER1_RETURNVALUE(void);



#endif /* TIMER1_H_ */
