/*
 * ADC.h
 *
 *  Created on: Sep 13, 2018
 *      Author: omar ehab
 */

#ifndef ADC_H_
#define ADC_H_
#include<avr/io.h>

void ADC_init(void);
short ADC_start(unsigned char channel);



#endif /* ADC_H_ */
