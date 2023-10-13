#include <stdio.h>
#include <stdlib.h>

#include "date.h"

int  getMonthLength( int month )
{
	// input your source code here
}


int  getDaySeq(int month, int day)
{
	// input your source code here
}


int  getNextMonday(int referenceDay)
{
	// input your source code here
}



void printOneDay(int daySeqOfYear)
{
	// input your source code here
}

int  getMonth(int daySeqOfYear)
{
	// input your source code here
}


int  getDay(int daySeqOfYear)
{
	// input your source code here
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
}

