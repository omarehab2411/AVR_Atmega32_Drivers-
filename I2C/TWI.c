/*
 * TWI.c
 *
 *  Created on: Nov 14, 2018
 *      Author: omar ehab
 */



#include "TWI.h"

void TWI_INIT(void)
{
TWBR=32;
TWSR&=~((1<<TWPS0)|(1<<TWPS1));
TWCR=(1<<TWEN)|(1<<TWEA);
}

void TWI_SEND_START(void)
{
TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
while((TWCR&(1<<TWINT))==0); //estna lma y5ls el operation bt3to
}

void TWI_SEND_DATA(unsigned char byte)
{
	TWDR=byte;
TWCR=(1<<TWINT)|(1<<TWEN);
	while((TWCR&(1<<TWINT))==0);
}

unsigned char TWI_RECEIVE_DATA(unsigned char last_byte)
{if(last_byte==0)
TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA); //Ack after each byte is sent
else
	TWCR=(1<<TWINT)|(1<<TWEN);
while((TWCR&(1<<TWINT))==0);
return (TWDR);
}


void TWI_SEND_STOP(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);

}


void TWI_SLAVE_INIT(unsigned char address)
{TWCR=(1<<TWEN);
TWAR=address;
TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	}

void TWI_LISTEN_BUS(void)
{
	while((TWCR&(1<<TWINT))==0); //awl lma el address bta3 el slave bigi el twint bib2a b 1 fna b poll l7d ma yb2a b 1 bm3na en el addres bta3 el slave galo
	}


void TWI_SEND_SLAVE (unsigned char byte)
{
TWDR=byte;
TWCR=(1<<TWINT)|(1<<TWEN);
//start transmition by raising interrupt flag that the bus is ready ;
while((TWCR&(1<<TWINT))==0); //bstna eno y5ls b3t el haga be loop di l2no lma y5ls hirf3 interrupt flag
}


unsigned char TWI_RECEIVE_SLAVE (unsigned char last_byte)
{
if(last_byte==0)
{TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA); }  //start receiving
else
{
	TWCR=(1<<TWINT)|(1<<TWEN);
}
while((TWCR&(1<<TWINT))==0);
return (TWDR);
}




