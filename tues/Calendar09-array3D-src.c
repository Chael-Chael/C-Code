/*
 * Filename:    school-calendar.c
 * Author:      Wei Liu, liuwei@hust.edu.cn
 * Date:        2019-9-1
 * Description:  Find the birthdays 
 *
 */

#include <stdio.h>
#include <stdlib.h>


// **************************************
// Constants used in this program
// **************************************
//
#define YEAR_NUM            8
#define YEAR_MIN            2016
#define YEAR_MAX            2023
#define DATE_INFO_BRIEF     1
#define DATE_INFO_FULL      2

// **************************************
// Functions used in this program
// **************************************
//
// Functions on different year
int  isLeapYear(int year );
int  getDaySeqOnJan1(int year);
//
// Functions about month and day
int  getDaySeq(int year, int month, int day);
int  getWeekSeqOfYear(int year, int month, int day);
// 
// Functions for properties of one day
int  getMonth(int year, int daySeqOfYear);
int  getDay(int year, int daySeqOfYear);
int  getDaySeqOfWeek(int year, int daySeqOfYear);
//
// Functions for day movement calculation
int  getThisMonday(int year, int daySeqOfYear);
int  getThisSunday(int year, int daySeqOfYear);
//
// Functions support school calendar display 
void printOneDay(int year, int daySeqOfYear, int formatType);
void printOneWeek(int year, int weekSeqOfYear, int weekSeqShow);
//
// Functions support multiple year
void setYearArray(int yearArray[], int yearNum, int yearStart);
void initialDays(int yearArray[], int daysArray[][366][4], int yearNum );


const int Month_NORMAL_YEAR [12] =
          {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int Month_LEAP_YEAR [12] =
          {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main( void )
{
    // Declare variables
    int inputMonth, inputDay, Years[YEAR_NUM];

    // Declare a three-demension array to record date information. 
    int Days[YEAR_NUM][366][4] = {0} ;
    //    1st demension: year, such as 2018, 2019, 2020, ...
    //    2nd demension: daySeqOfYear, such as 1, 2, 3, ..., 365, 366
    //    3rd demension: detailed information for each day
    //        Days[..][..][0]: month
    //        Days[..][..][1]: day
    //        Days[..][..][2]: weekSeqOfYear
    //        Days[..][..][3]: daySeqOfWeek

    // Display the program information
    printf("Finding Birthday in year (%d-%d), please input the month and day : \n", 
           YEAR_MIN, YEAR_MAX ); 
    scanf("%d%d" , &inputMonth, &inputDay );
    
    if ( inputMonth < 1 || inputMonth > 12 || inputDay < 1 || inputDay > 31 )
    {
        printf("Sorry, the input month and day are invalid.\n");
        return 1;
    }    

    setYearArray ( Years, YEAR_NUM, YEAR_MIN );
    initialDays ( Years, Days, YEAR_NUM );

    int totalNum = 0, weekendNum = 0;

    // Requirement: finish the rest functions
    // 1. the print related sentences:
    //    printf("\n%s%s%d\n", " ", "Birthday in Year ", year );
    //    printf(" #M:%10s%10s%10s%10s%10s%10s%10s\n", 
    //           "Mon.","Tues.","Wed.","Thur.","Fri.","Sat.","Sun.");
    //    printf(" Not found.\n");
    // 2. the print related function calling:
    //    printOneWeek ( year, weekSeq, month );
    // 
    // **********************************************
    // << Your source code starts here >>
    //
    for (int i = 0; i < YEAR_NUM; i ++)
    {
        int isFound = 0;
        printf("\n%s%s%d\n", " ", "Birthday in Year ", Years[i] );
        int j;
        for (j = 0; j < (isLeapYear( Years[i] ) ? 366 : 365); j++)
        {
            if (Days[i][j][0] == inputMonth && Days[i][j][1] == inputDay)
            {
                isFound = 1;
                totalNum ++;
                if (Days[i][j][3] == 6 || Days[i][j][3] == 5)
                {
                    weekendNum ++;
                }
                break;
            }
            else{}

        }

        if (isFound == 0)
        {
            printf(" Not found.\n");
        }
        else
        {
            printf(" #M:%10s%10s%10s%10s%10s%10s%10s\n", 
               "Mon.","Tues.","Wed.","Thur.","Fri.","Sat.","Sun.");
            printOneWeek ( Years[i], Days[i][j][2], inputMonth);
        }
       
    }
    printf("Total %d birthday are found, %d of them are in weekends.\n", totalNum, weekendNum );
    //
    // << Your source code stops here >>
    // **********************************************

    printf("\nTotal %d birthday are found, %d of them are in weekends.\n", totalNum, weekendNum );

    return 0;
}


int isLeapYear( int year )
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) ;
}
//isLeapYear returns 1 if the year is a leap year, otherwise returns 0


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

int getDaySeq(int year, int month, int day)
{
    int daySeqOfYear = 0;
    int i;

    for ( i = 1; i < month; i ++ )
    {
        daySeqOfYear += ( isLeapYear(year) == 1 ) ? Month_LEAP_YEAR[i-1] : Month_NORMAL_YEAR[i-1];
    }

    daySeqOfYear += day;

    return daySeqOfYear;
}

int getWeekSeqOfYear(int year, int month, int day)
{
    int daySeqOfYear = getDaySeq( year, month, day );
    int daySeqOnJan1 = getDaySeqOnJan1( year );

    return ( daySeqOfYear + daySeqOnJan1 ) / 7;
}

int getMonth(int year, int daySeqOfYear)
{
    int i;
    int daySeq = 0;

    for ( i = 1; i <= 12; i ++ )
    {
        daySeq += ( isLeapYear(year) == 1 ) ? Month_LEAP_YEAR[i-1] : Month_NORMAL_YEAR[i-1];
        if ( daySeq >= daySeqOfYear )
        {
            return i;
        }
    }

    return 0;
}

int getDay(int year, int daySeqOfYear)
{
    int i;
    int daySeq = 0;

    for ( i = 1; i <= 12; i ++ )
    {
        daySeq += ( isLeapYear(year) == 1 ) ? Month_LEAP_YEAR[i-1] : Month_NORMAL_YEAR[i-1];
        if ( daySeq >= daySeqOfYear )
        {
            return daySeqOfYear - ( daySeq - ( isLeapYear(year) == 1 ) ? Month_LEAP_YEAR[i-1] : Month_NORMAL_YEAR[i-1] );
        }
    }

    return 0;
}

int getDaySeqOfWeek(int year, int daySeqOfYear)
{
    int daySeqOnJan1 = getDaySeqOnJan1( year );
    int daySeq = daySeqOfYear + daySeqOnJan1;

    return daySeq % 7;
}

int getThisMonday(int year, int daySeqOfYear)
{
    int daySeqOnJan1 = getDaySeqOnJan1( year );
    int daySeq = daySeqOfYear + daySeqOnJan1;

    return daySeq - ( daySeq % 7 );
}

int getThisSunday(int year, int daySeqOfYear)
{
    int daySeqOnJan1 = getDaySeqOnJan1( year );
    int daySeq = daySeqOfYear + daySeqOnJan1;

    return daySeq - ( daySeq % 7 ) + 6;
}

void printOneWeek (int year, int weekSeqOfYear, int weekSeqShow)
{
    int daySeqOfYear = weekSeqOfYear * 7 + 1;
    int daySeqOfWeek = getDaySeqOfWeek( year, daySeqOfYear );
    int month = getMonth( year, daySeqOfYear );
    int day = getDay( year, daySeqOfYear );

    int i;
    for ( i = 0; i < 7; i ++ )
    {
        if ( daySeqOfWeek == i )
        {
            printOneDay( year, daySeqOfYear, DATE_INFO_BRIEF );
            daySeqOfYear ++;
            daySeqOfWeek = getDaySeqOfWeek( year, daySeqOfYear );
        }
        else
        {
            printf("%10s", " ");
        }
    }

    printf("\n");

    return;
}


void printOneDay(int year, int daySeqOfYear, int formatType )
{
    int month = getMonth( year, daySeqOfYear );
    int day = getDay( year, daySeqOfYear );
    int daySeqOfWeek = getDaySeqOfWeek( year, daySeqOfYear );

    int isWeekend = (daySeqOfWeek == 6 || daySeqOfWeek == 5 );
    int isFullInfo = ( formatType == DATE_INFO_FULL ) ? 1 : 0;
    isFullInfo = ( month == 1 && day == 1 ) ? 1 : isFullInfo;

    // For the case of first day of one year, shows full info
    if ( isFullInfo )
    {
        if ( isWeekend ) 
        {
            printf("%3d.%02d.%02d!", year % 100, month, day );
        }
        else
        {
            printf("%4d.%02d.%02d", year % 100, month, day );
        }
        return ;
    }

    // Otherwise, print the date in brief format, only shows month for the first day
    int isMonthFirst = ( day == 1 );

    if ( isMonthFirst && isWeekend )
    {
        printf("%4s%02d.%02d!", " ", month, day);
    }
    else if ( isMonthFirst && !isWeekend )
    {
        printf("%5s%02d.%02d", " ", month, day);
    }
    else if ( !isMonthFirst && isWeekend )
    {
        printf("%7s%2d!", " ", day);
    }
    else if ( !isMonthFirst && !isWeekend )
    {
        printf("%8s%2d", " ", day);
    }

    return;
}


void setYearArray(int yearArray[], int yearNum, int yearStart)
{
    int i;
    
    for ( i = 0; i < yearNum; i ++ )
    {
        yearArray[i] = yearStart + i;
    }

    return; 
}


void initialDays(int Years[], int Days[][366][4], int yearNum )
{
    int year, month, day, yearLength, weekSeq, seqOfWeek;
    int i, j;

    for ( i = 0 ; i < YEAR_NUM ; i ++ )
    {
        year = Years[i];
        yearLength = isLeapYear( year ) ? 366 : 365;
        for ( j = 0 ; j < yearLength; j ++ )
        {
            Days[i][j][0] = getMonth( year, j + 1 );
            Days[i][j][1] = getDay( year, j + 1 );
            Days[i][j][2] = getWeekSeqOfYear( year, Days[i][j][0], Days[i][j][1] );
            Days[i][j][3] = getDaySeqOfWeek( year, j + 1 );
        }
    }

    return;    
}


