/*
 * RTC.c
 *
 *  Created on: Jan 21, 2019
 *      Author: omar ehab
 */

#include "RTC.h"


void RTC_INIT(void)
{
TWI_INIT();
TWI_SEND_START();
TWI_SEND_DATA(0b11010000);
TWI_SEND_DATA(0x07);
TWI_SEND_DATA(0x00);
TWI_SEND_STOP();
TWI_SEND_START();
TWI_SEND_DATA(0b11010000);
TWI_SEND_DATA(0x02);
TWI_SEND_DATA(0b01000000);
TWI_SEND_STOP();
}
void RTC_SET(struct RTC *ptr)
{
TWI_SEND_START();
TWI_SEND_DATA(0b11010000);
TWI_SEND_DATA(0x00);
TWI_SEND_DATA(ptr->sec);
TWI_SEND_DATA(ptr->min);
TWI_SEND_DATA(ptr->hour);
TWI_SEND_DATA(ptr->day);
TWI_SEND_DATA(ptr->date);
TWI_SEND_DATA(ptr->month);
TWI_SEND_DATA(ptr->year);
TWI_SEND_STOP();
}
void RTC_GET(struct RTC *ptr2)
{

TWI_SEND_START();
TWI_SEND_DATA(0b11010000);
TWI_SEND_DATA(0x00);
TWI_SEND_STOP();
TWI_SEND_START();
TWI_SEND_DATA(0b11010001);

ptr2->sec=BCD2DEC(TWI_RECEIVE_DATA(0));
ptr2->min=BCD2DEC(TWI_RECEIVE_DATA(0));
ptr2->hour=BCD2DEC(TWI_RECEIVE_DATA(0));
ptr2->day=BCD2DEC(TWI_RECEIVE_DATA(0));
ptr2->date=BCD2DEC(TWI_RECEIVE_DATA(0));
ptr2->month=BCD2DEC(TWI_RECEIVE_DATA(0));
ptr2->year=BCD2DEC(TWI_RECEIVE_DATA(1));

TWI_SEND_STOP();
}


/*struct RTC *RTC_STRUCT_FILL(int sec,int min,int hour,int date,int day,int month,int year)
{

ptr=&rtc;
rtc.sec=DEC2BCD(sec);
rtc.min=DEC2BCD(min);
rtc.hour=DEC2BCD(hour);
rtc.date=DEC2BCD(date);
rtc.day=DEC2BCD(day);
rtc.month=DEC2BCD(month);
rtc.year=DEC2BCD(year);
return ptr;
}*/



int DEC2BCD(int num)
{

	 return (((num/10) << 4) | (num % 10));
}



int BCD2DEC(int BCD)
{
	return (((BCD>>4)*10) + (BCD & 0xF));

}




