/*
 * Timer0.h
 *
 *  Created on: Sep 11, 2018
 *      Author: omar ehab
 */

#ifndef TIMER0_H_
#define TIMER0_H_

void Timer0_init(void);
void Timer0_start(void);
void Timer0_stop(void);
void Timer0_clear(void);
void Timer0_showvalue(unsigned char *Address);
void Timer0_PWM_INIT(void);
void Timer0_PWM_DUTYCYCLE(int duty_cycle);
void Timer0_CTC_INIT(void);
void Timer0_CTC_VALUE(int match_value);
void Timer0_CTC_START(void);
void Timer0_CTC_STOP(void);
void Timer0_COUNTERMODE_START(void);
#endif /* TIMER0_H_ */
