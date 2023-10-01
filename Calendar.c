#include <stdio.h>
#include <stdlib.h>

#define CURRENT_YEAR 2023
#define WEEKDAY_JAN1 7
#define IS_LEAPYEAR 0

int main()
{
    int month, day, daySeqOfWeek, TotalDays;

    printf("Week Day Calculator of Year %d, please input month(1-12) day(1-31): ", CURRENT_YEAR);
    scanf("%d %d", &month, &day);

    if(month == 1)
    {
        if(day <= 31 && day > 0)
        {
            TotalDays = day;
        }
        else
        {
            printf("Error");
            exit(0);
        }
    }
    else if(month == 2)
    {
        if(day <= 28 && day > 0)
        {
            TotalDays = day + 31;
        }
        else
        {
            printf("Error");
            exit(0);
        }
    }
    else if(month == 3)
    {
        if(day <= 31 && day > 0)
        {
            TotalDays = day + 59;
        }
        else
        {
            printf("Error");
            exit(0);
        }
    }
    else if(month == 4)
    {
         if(day <= 30 && day > 0)
        {
            TotalDays = day + 90;
        }
        else
        {
            printf("Error");
            exit(0);
        }
    }
    else if(month == 5)
    {
         if(day <= 31 && day > 0)
        {
            TotalDays = day + 120;
        }
        else
        {
            printf("Error");
            exit(0);
        }
    }
    else if(month == 6)
    {
         if(day <= 30 && day > 0)
        {
            TotalDays = day + 151;
        }
        else
        {
            printf("Error");
            exit(0);
        }
    }
    else if(month == 7)
    {
         if(day <= 31 && day > 0)
        {
            TotalDays = day + 181;
        }
        else
        {
            printf("Error");
            exit(0);
        }
    }
    else if(month == 8)
    {
         if(day <= 31 && day > 0)
        {
            TotalDays = day + 212;
        }
        else
        {
            printf("Error");
            exit(0);
        }
    }
    else if(month == 9)
    {
         if(day <= 30 && day > 0)
        {
            TotalDays = day + 243;
        }
        else
        {
            printf("Error");
            exit(0);
        }
    }
    else if(month == 10)
    {
         if(day <= 31 && day > 0)
        {
            TotalDays = day + 273;
        }
        else
        {
            printf("Error");
            exit(0);
        }
    }
    else if(month == 11)
    {
         if(day <= 30 && day > 0)
        {
            TotalDays = day + 304;
        }
        else
        {
            printf("Error");
            exit(0);
        }
    }
    else if(month == 12)
    {
         if(day <= 31 && day > 0)
        {
            TotalDays = day + 334;
        }
        else
        {
            printf("Error");
            exit(0);
        }
    }
    else{
        printf("Error");
        exit(0);
    }

    switch(TotalDays % 7)
    {
        case 1 :
            daySeqOfWeek = 7;
            break;
        case 2 :
            daySeqOfWeek = 1;
            break;
        case 3 :
            daySeqOfWeek = 2;
            break;
        case 4 :
            daySeqOfWeek = 3;
            break;
        case 5 :
            daySeqOfWeek = 4;
            break;
        case 6 :
            daySeqOfWeek = 5;
            break;
        case 0 :
            daySeqOfWeek = 6;
            break;
    }

    printf("%d-%d-%d is No.%d day in that week.\n\n",CURRENT_YEAR, month, day, daySeqOfWeek);
    return 0;
}
