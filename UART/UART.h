/*
 * UART.h
 *
 *  Created on: Aug 11, 2016
 *      Author: ahmed
 */

#ifndef UART_H_
#define UART_H_

#include <avr/io.h>

void Uart_init(long BaudRate);
void UART_send_byte( char byte);
void UART_send_string( char *ptr);
char UART_recieve_byte(void);
void UART_recieve_string( char *ptr);


#endif /* UART_H_ */
