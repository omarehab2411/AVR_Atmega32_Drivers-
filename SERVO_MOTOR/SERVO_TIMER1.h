/*
 * SERVO_TIMER1.h
 *
 *  Created on: Apr 27, 2019
 *      Author: omar ehab
 */

#ifndef SERVO_TIMER1_H_
#define SERVO_TIMER1_H_
#include <avr/io.h>
void SERVO_MOTOR_INIT(unsigned short int TOP_VALUE);
void SERVO_MOTOR_START(void);
void SERVO_MOTOR_DUTYCYCLE(unsigned short int DUTY_CYCLE);
void SERVO_MOTOR_STOP(void);
#endif /* SERVO_TIMER1_H_ */
