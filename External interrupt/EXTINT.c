/*
 * EXTINT.c
 *
 *  Created on: Apr 15, 2019
 *      Author: omar ehab
 */


#include "EXTINT.h"

void EXT_INT_ENABLE(char mode)
{
SREG|=(1<<7);
if(mode=='1'){
MCUCR|=(1<<ISC10)|(1<<ISC11);
GICR|=(1<<INT1);
}
 if(mode=='0')
	{MCUCR|=(1<<ISC01)|(1<<ISC00);
GICR|=(1<<INT0);
}
 if(mode=='3')
{MCUCR|=(1<<ISC10)|(1<<ISC11);
GICR|=(1<<INT1);
MCUCR|=(1<<ISC01)|(1<<ISC00);
GICR|=(1<<INT0);}
	}
void EXT_INT_DISABLE(char mode){

	if(mode=='1'){
	MCUCR&=~((1<<ISC10)|(1<<ISC11));
	GICR&=~(1<<INT1);
	}
	 if(mode=='0')
		{MCUCR&=~((1<<ISC01)|(1<<ISC00));
	GICR&=~(1<<INT0);
	}
	 if(mode=='3')
	{MCUCR&=~((1<<ISC10)|(1<<ISC11));
	GICR&=~(1<<INT1);
	MCUCR&=~((1<<ISC01)|(1<<ISC00));
		GICR&=~(1<<INT0);
		}
}

int EXT_INT_FLAG(char mode){

	if(mode=='0')
	{
		return GIFR&=(1<<INTF1);
	}
	else if(mode=='1')
	{
		return GIFR&=(1<<INTF0);
	}
}
