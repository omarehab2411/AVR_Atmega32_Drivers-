/*
 * BLUETOOTH.c
 *
 *  Created on: Dec 15, 2018
 *      Author: omar ehab
 */


#include "BLUETOOTH.h"

void BLUETOOTH_INIT(long baud){
Uart_init(baud);
}
void BLUETOOTH_SENDBYTE(char byte){
UART_send_byte(byte);
}
void BLUETOOTH_SENDSTRING(char *ptr)
{UART_send_string(ptr);
	}
char BLUETOOTH_RECEIVEBYTE(void)
{return (UART_recieve_byte());
	}
void BLUETOOTH_RECEIVESTRING(char *ptr)
{UART_recieve_string(ptr);

}


