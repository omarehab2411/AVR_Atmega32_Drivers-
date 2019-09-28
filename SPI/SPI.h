/*
 * SPI.h
 *
 *  Created on: Nov 12, 2018
 *      Author: omar ehab
 */

#ifndef SPI_H_
#define SPI_H_
#define MOSI PB5
#define SCK  PB7
#define  MISO PB6
#define  SS   PB4

#include <avr/io.h>

void SPI_MASTER_INIT(void);
void SPI_SLAVE_INIT(void);
void SPI_MASTER_TRANSMIT(unsigned char byte);
unsigned char SPI_SLAVE_RECEIVE (void);



#endif /* SPI_H_ */
