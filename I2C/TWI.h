/*
 * TWI.h
 *
 *  Created on: Nov 14, 2018
 *      Author: omar ehab
 */

#ifndef TWI_H_
#define TWI_H_
#include <avr/io.h>

void TWI_INIT(void);
void TWI_SEND_START(void);
void TWI_SEND_DATA(unsigned char byte);
unsigned char TWI_RECEIVE_DATA(unsigned char last_byte);
void TWI_SEND_STOP(void);

void TWI_SLAVE_INIT(unsigned char address);
void TWI_LISTEN_BUS(void);
void TWI_SEND_SLAVE (unsigned char byte);
unsigned char TWI_RECEIVE_SLAVE (unsigned char last_byte);


#endif /* TWI_H_ */
