#include <stdio.h>
#include <stdlib.h>

#include "date.h"

int  getMonthLength( int month )
{
	// input your source code here
	int days;
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: 
            days = 31;
            break;
        case 2:
            days = IS_LEAPYEAR ? 29 : 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        default:
            days = 0;
            break;
    }
    return days;
}


int getDaySeq(int month, int day)
{
	// input your source code here
	int totaldays;
	for(int i = 1; i <= month - 1; i++)
	{
		totaldays += getMonthLength(i);
	}
	totaldays += day;
	return totaldays;
}


int  getNextMonday(int referenceDay)
{
	// input your source code here
	if (getDaySeqOfWeek(referenceDay) != 0)
	{
		referenceDay = referenceDay + 7 - getDaySeqOfWeek(referenceDay);
	}
}



void printOneDay(int daySeqOfYear)
{
	// input your source code here;
    printf("     %02d.%02d",getMonth(daySeqOfYear), getDay(daySeqOfYear));
}

int  getMonth(int daySeqOfYear)
{
	// input your source code here
	int month = 1, totaldays = 0;
    while(totaldays < daySeqOfYear)
    {
        totaldays += getMonthLength(month);
        month += 1;
    }
	return month-1;
}


int  getDay(int daySeqOfYear)
{
	int totaldays = 0, i, date;
	for(i = 1; i < getMonth(daySeqOfYear); i++)
	{
		totaldays += getMonthLength(i);
	}
	date = daySeqOfYear - totaldays;
	return date;
}


int  getDaySeqOfWeek(int daySeqOfYear)
{
    // assume one week starts with Monday
    // 0,1,2,3,4,5,6 stands for Monday, Tuesday, ..., Sunday
    return  ( daySeqOfYear + WEEKDAY_JAN1 - 1 ) % 7;
}


int  getThisSunday(int referenceDay)
{
	// input your source code here
	if (getDaySeqOfWeek(referenceDay) != 6)
	{
		referenceDay = referenceDay + 6 - getDaySeqOfWeek(referenceDay);
	}
}

