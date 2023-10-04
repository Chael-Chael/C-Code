#include <stdio.h>
//获得每月天数
int getmonthlength(int month)
{
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
            days = 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        case 0:
            days = 0;
            break;
    }
    return days;
}
//获得2023年任意日是周几
int getseq(int TotalDays)
{
    int daySeqOfWeek;
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

    return daySeqOfWeek;
}
//对任意天执行getdate
int getdate(int days, int array[2])
{
    int month = 1, totaldays = 0, date;
    while(totaldays < days)
    {
        totaldays += getmonthlength(month);
        month += 1;
    }
    date = days - totaldays + getmonthlength(month-1);
    array[0] = month-1;
    array[1] = date;
}

int main()
{
    while(1)
    {
        int week, FirstDay, LastDay, FirstDaySeq, LastDaySeq;
        printf("Week Calendar of Year 2023, please input week sequence(1-53):\n");
        scanf("%d", &week);

        //报错提醒
        while(week < 1 || week > 53)
        {
            printf("invalid input\n");
            printf("Week Calendar of Year 2023, please input week sequence(1-53):\n");
            scanf("%d", &week);
        }

        //First/Last Day Seq
        FirstDay = 2 + (week-2) * 7;
        LastDay = 1 + (week-1) *7;

        
        //Print Header
        char a[] = "Mon.", b[] = "Tues." , c[] = "Wend.", h[] = "Thur.", e[] = "Fri.", f[] = "Stat." ,g[] = "Sun.";
        printf("#w:%10s%10s%10s%10s%10s%10s%10s\n",a,b,c,h,e,f,g);
        printf("%02d:",week);

        //Print Week
        int i, d = 1, array[2]={0,0};
        char space[] = " ";
        if(week > 1 && week < 53)
        {
            for(i = FirstDay; i <= LastDay; i++)
            {
                getdate(i, array);
                printf("%5s", space);
                printf("%02d.%02d", array[0], array[1]);
            }
        }
        else if(week == 1)
        {
            for(i = 1; i <= 13; i++)
            {
                printf("%5s", space);
            }
            printf("%02d.%02d",1, 1);
        }
        else
        {
            for(i = FirstDay; i <= 365; i++)
            {
                getdate(i, array);
                printf("%5s", space);
                printf("%02d.%02d", array[0], array[1]);
            }
        }

        int exit;
        printf("\nInput 1 to continue and 0 to exit\n");
        scanf("%d", &exit);
        if(exit == 0)
        {
            break;
        }
    }
}