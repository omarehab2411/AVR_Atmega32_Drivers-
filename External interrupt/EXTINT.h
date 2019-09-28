/*
 * EXTINT.h
 *
 *  Created on: Apr 15, 2019
 *      Author: omar ehab
 */

#ifndef EXTINT_H_
#define EXTINT_H_
#include <avr/io.h>

void EXT_INT_ENABLE(char mode);
void EXT_INT_DISABLE(char mode);
int EXT_INT_FLAG(char mode);


#endif /* EXTINT_H_ */
