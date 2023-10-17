/*
 * Filename:    school-calendar.c
 * Author:      Wei Liu, liuwei@hust.edu.cn
 * Date:        2019-9-1
 * Description:  Print the school calendar of 2020 fall
 *
 */

#include <stdio.h>
#include <stdlib.h>

// **************************************
// Functions used in this program
// **************************************
//
// Functions on different year
int  isLeapYear(int year );
int  getDaySeqOnJan1(int year);
//
// Functions about month and day
int  getMonthLength(int year, int month);
int  getDaySeq(int year, int month, int day);
// 
// Functions for properties of one day
int  getMonth(int year, int daySeqOfYear);
int  getDay(int year, int daySeqOfYear);
int  getDaySeqOfWeek(int year, int daySeqOfYear);
//
// Functions for day movement calculation
int  getNextMonday(int year, int daySeqOfYear);
int  getThisMonday(int year, int daySeqOfYear);
int  getThisSunday(int year, int daySeqOfYear);
//
// Functions support school calendar display 
void printOneDay(int year, int daySeqOfYear);


int main( void )
{

    // Declare variables
    const int currentYear = 2023;
    int referenceDay;

    // Display the program information
    printf("Fall Semester Calendar of Year %d, please input reference day in the Next Jan(1-%d): \n",
           currentYear, getMonthLength(currentYear + 1, 1) );
    scanf("%d" , &referenceDay );

    // Display the program information
    printf("%18s%s%d\n", " ", "Fall Semester Calendar of Year ", currentYear );

    // Print the header of table
    printf(" #W:%10s%10s%10s%10s%10s%10s%10s\n",
               "Mon.","Tues.","Wed.","Thur.","Fri.","Sat.","Sun.");

    if ( referenceDay < 1 || referenceDay > getMonthLength(currentYear + 1, 1) )
    {
        printf("Error input. reference day is set to Jan 15.\n");
        referenceDay = 15;
    }

    // Calculate the first day in this fall
    int sStartSeqOfYear = getDaySeq(currentYear, 9, 1); 
    sStartSeqOfYear = getThisMonday(currentYear, sStartSeqOfYear);

    // Calculate the last day in the next spring 
    int sEndSeqOfYear = getDaySeq(currentYear + 1, 1, referenceDay);
    sEndSeqOfYear = getThisSunday( currentYear + 1, sEndSeqOfYear );

    // Transfer the daySeq into the same start in this fall
    int currentYearLength = ( isLeapYear( currentYear ) == 1 ) ? 366 : 365;
    sEndSeqOfYear += currentYearLength;

    // Declare variables to navigate the semester
    int daySeqOfYear, daySeqOfWeek, weekSeqOfSemester;

    // Print the semester calendar
    for ( daySeqOfYear = sStartSeqOfYear, daySeqOfWeek = 0, weekSeqOfSemester = 1;  
          daySeqOfYear <= sEndSeqOfYear;  
          daySeqOfYear ++, daySeqOfWeek ++, daySeqOfWeek %= 7 )
    {
        // Before Monday, print the week sequence
        if ( daySeqOfWeek == 0 )
        {
            printf("[%02d]", weekSeqOfSemester );
        }

        // Print the month and day for the current day
        if ( daySeqOfYear <= currentYearLength )
        {
            printOneDay( currentYear, daySeqOfYear );
        }
        else 
        {
            printOneDay( currentYear + 1, daySeqOfYear - currentYearLength );
        }
        

        // After Sunday, print a new line
        if ( daySeqOfWeek == 6 )
        {
            printf("\n");
            weekSeqOfSemester ++;
        }
    }

    printf("\n");

    return 0;
}

//leapyear return 1
int isLeapYear( int year )
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) ;
}



int getDaySeqOnJan1(int year)
{
    if ( year < 1900 )
    {
        printf("Error: this year is not supported. \n");
        return 0;
    }

    // given, 1900-1-1 is Monday
    int seqYear;
    int totalDays = 0;

    for ( seqYear = 1900; seqYear < year; seqYear ++ )
    {
        totalDays += ( isLeapYear(seqYear) == 1 ) ? 366 : 365;
    }

    return totalDays % 7;
}


void printOneDay(int year, int daySeqOfYear)
{
    int month = getMonth( year, daySeqOfYear );
    int day = getDay( year, daySeqOfYear );
    int daySeqOfWeek = getDaySeqOfWeek( year, daySeqOfYear );

    if ( day == 1 )
    { // If this is the first day of month, show month
        if ( daySeqOfWeek == 6 || daySeqOfWeek == 5  )
        {
            printf("%4s%02d.%02d!", " ", month, day);
        }
        else
        {
            printf("%5s%02d.%02d", " ", month, day);
        }
    }
    else
    { // Otherwise, just show day
        if ( daySeqOfWeek == 6 || daySeqOfWeek == 5  )
        {
            printf("%5s%4d!", " ", day);
        }
        else
        {
            printf("%5s%5d", " ", day);
        }
    }
}


int  getMonthLength( int year, int month )
{
    int mLength;
    
// **********************************************
// << Write your source code here >>
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: 
            mLength = 31;
            break;
        case 2:
            mLength = isLeapYear(year) ? 29 : 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            mLength = 30;
            break;
    }
// **********************************************

    return mLength;

}


int  getDaySeq( int year, int month, int day)
{
    int lengthJan = 31;
    int lengthFeb = ( isLeapYear(year) == 1 ) ? lengthJan + 29 : lengthJan + 28;
    int lengthMar = lengthFeb + 31;
    int lengthApr = lengthMar + 30;
    int lengthMay = lengthApr + 31;
    int lengthJun = lengthMay + 30;
    int lengthJul = lengthJun + 31;
    int lengthAug = lengthJul + 31;
    int lengthSep = lengthAug + 30;
    int lengthOct = lengthSep + 31;
    int lengthNov = lengthOct + 30;
    int lengthDec = lengthNov + 31;

    int daySeq = 0;
    
// **********************************************
// << Write your source code here >>
    switch(month)
    {
        case 1:
            daySeq = day;
            break;
        case 2:
            daySeq = lengthJan + day;
            break;
        case 3:
            daySeq = lengthFeb + day;
            break;
        case 4:
            daySeq = lengthMar + day;
            break;
        case 5:
            daySeq = lengthApr + day;
            break;
        case 6:
            daySeq = lengthMay + day;
            break;
        case 7:
            daySeq = lengthJun + day;
            break;
        case 8:
            daySeq = lengthJul + day;
            break;
        case 9:
            daySeq = lengthAug + day;
            break;
        case 10:
            daySeq = lengthSep + day;
            break;
        case 11:
            daySeq = lengthOct + day;
            break;
        case 12:
            daySeq = lengthNov + day;
            break;
    }
// **********************************************

    return daySeq; 
}


int  getMonth(int year, int daySeqOfYear)
{

    int lengthJan = 31;
    int lengthFeb = ( isLeapYear(year) == 1 ) ? lengthJan + 29 : lengthJan + 28;
    int lengthMar = lengthFeb + 31;
    int lengthApr = lengthMar + 30;
    int lengthMay = lengthApr + 31;
    int lengthJun = lengthMay + 30;
    int lengthJul = lengthJun + 31;
    int lengthAug = lengthJul + 31;
    int lengthSep = lengthAug + 30;
    int lengthOct = lengthSep + 31;
    int lengthNov = lengthOct + 30;
    int lengthDec = lengthNov + 31;

    int month = 0 ;

// **********************************************
// << Write your source code here >>

// **********************************************

    return month;
}


int  getDay(int year, int daySeqOfYear)
{

    int lengthJan = 31;
    int lengthFeb = ( isLeapYear(year) == 1 ) ? lengthJan + 29 : lengthJan + 28;
    int lengthMar = lengthFeb + 31;
    int lengthApr = lengthMar + 30;
    int lengthMay = lengthApr + 31;
    int lengthJun = lengthMay + 30;
    int lengthJul = lengthJun + 31;
    int lengthAug = lengthJul + 31;
    int lengthSep = lengthAug + 30;
    int lengthOct = lengthSep + 31;
    int lengthNov = lengthOct + 30;
    int lengthDec = lengthNov + 31;

    int day = 0;

// **********************************************
// << Write your source code here >>
// **********************************************

    return day;
}


int  getDaySeqOfWeek(int year, int daySeqOfYear)
{
    // assume one week starts with Monday
    // 0,1,2,3,4,5,6 stands for Monday, Tuesday, ..., Sunday

    return  ( daySeqOfYear + getDaySeqOnJan1(year) - 1 ) % 7;
}


int  getNextMonday(int year, int referenceDay)
{
    int daySeqOfYear;

// **********************************************
// << Write your source code here >>
// **********************************************

    return daySeqOfYear;
}


int  getThisMonday(int year, int referenceDay)
{
    int daySeqOfYear;

// **********************************************
// << Write your source code here >>
// **********************************************

    return daySeqOfYear;
}


int  getThisSunday(int year, int referenceDay)
{
    int daySeqOfYear;

// **********************************************
// << Write your source code here >>
// **********************************************

    return daySeqOfYear;
}

