#include <stdio.h>

const int Month_NORMAL_YEAR [12] =
          {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int Month_LEAP_YEAR [12] =
          {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isLeapYear(int year )
{
    if (year % 400 == 0)
        return 1;
    else if (year % 100 == 0)
        return 0;
    else if (year % 4 == 0)
        return 1;
    else
        return 0;
}

int  getDay(int year, int daySeqOfYear)
{
    int i = 0, day = 0;
    while (daySeqOfYear > (( isLeapYear (year) == 1) ? Month_LEAP_YEAR[i] : Month_NORMAL_YEAR[i]))
    {
        daySeqOfYear -= ( isLeapYear (year) == 1) ? Month_LEAP_YEAR[i] : Month_NORMAL_YEAR[i];
        i ++;
    }

    day = daySeqOfYear;
    return day;
}


int main()
{
    int year, daySeqOfYear;
    printf("Please input the year and the day sequence of the year: ");
    scanf("%d %d", &year, &daySeqOfYear);

    printf("The day of the year is %d\n", getDay(year, daySeqOfYear));

    return 0;
}

