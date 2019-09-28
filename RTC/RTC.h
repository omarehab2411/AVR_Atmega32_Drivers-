/*
 * RTC.h
 *
 *  Created on: Jan 21, 2019
 *      Author: omar ehab
 */

#include <avr/io.h>
#include "TWI.h"

struct RTC{
	int sec;
	int min;
	int hour;
	int date;
	int day;
	int month;
	int year;
};

void RTC_INIT(void);
void RTC_SET(struct RTC *ptr);
void  RTC_GET(struct RTC *ptr2);
//struct RTC *RTC_STRUCT_FILL(int sec,int min,int hour,int date,int day,int month,int year);
int DEC2BCD(int num);
int BCD2DEC(int BCD);

#ifndef RTC_H_
#define RTC_H_



#endif /* RTC_H_ */
