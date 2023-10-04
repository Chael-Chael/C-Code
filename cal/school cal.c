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
        int rday, week = 1, startday;
        printf("Spring Semester Calendar of Year 2023, please input reference day in Feb(1-28):\n");
        scanf("%d", &rday);

        while(rday < 1 || rday > 28)
        {
            printf("invalid input\n");
            printf("Spring Semester Calendar of Year 2023, please input reference day in Feb(1-28):\n");
            scanf("%d", &rday);
        }

        startday = rday + 31;

        //Print Header
        char a[] = "Mon.", b[] = "Tues." , c[] = "Wend.", h[] = "Thur.", e[] = "Fri.", f[] = "Sat." ,g[] = "Sun.";
        printf("\n");
        printf("#w:%11s%11s%10s%10s%10s%10s%10s\n",a,b,c,h,e,f,g);

        //Print Week
        int i, j, d = 1, array[2]={0,0}, startseq;
        char space[] = " ";

        printf("[%02d]:",week);

        startseq = getseq(startday+7);


        for(j = 1; j < startseq; j++)
        {
            printf("%10s", space);
        }

        for(i = startday + 7; i <= 183; j++, i++)
        {
            getdate(i, array);
            printf("%5s", space);
            printf("%02d.%02d", array[0], array[1]);
            if(j%7 == 0 && i < 183)
            {
                week++;
                printf("\n");
                printf("[%02d]:",week);
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