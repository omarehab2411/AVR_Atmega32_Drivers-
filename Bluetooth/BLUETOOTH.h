/*
 * BLUETOOTH.h
 *
 *  Created on: Dec 15, 2018
 *      Author: omar ehab
 */

#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_
#include "UART.h"

void BLUETOOTH_INIT(long baud);
void BLUETOOTH_SENDBYTE(char byte);
void BLUETOOTH_SENDSTRING(char *ptr);
char BLUETOOTH_RECEIVEBYTE(void);
void BLUETOOTH_RECEIVESTRING(char *ptr);

#endif /* BLUETOOTH_H_ */
