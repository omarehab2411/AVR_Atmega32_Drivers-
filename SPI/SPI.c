/*
 * SPI.c
 *
 *  Created on: Nov 12, 2018
 *      Author: omar ehab
 */



#include "SPI.h"


void SPI_MASTER_INIT(void)
{

	DDRB|=(1<<MOSI)|(1<<SCK)|(1<<SS);
	PORTB|=(1<SS);
	SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<SPR1);

}

void SPI_SLAVE_INIT(void)
{
	DDRB|=(1<<MISO);
	SPCR|=(1<<SPE);

	}

void SPI_MASTER_TRANSMIT(unsigned char byte)
{char SLAVE_RETURN;
	PORTB&=~(1<<SS);
	SPDR=byte;
while((SPSR&(1<<SPIF))==0);
SLAVE_RETURN=SPDR;
PORTB|=(1<<SS);
}

unsigned char SPI_SLAVE_RECEIVE (void)
{while((SPSR&(1<<SPIF))==0);
return (SPDR);

}


