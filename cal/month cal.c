#include <stdio.h>
int main()
{
    int month, days, daySeqOfWeek;
    printf("Month Calendar of Year 2023, please input month(1-12)\n");
    scanf("%d", &month);

    //报错提醒
    while(month < 1 || month > 12)
    {
        printf("invalid input\n");
        printf("Month Calendar of Year 2023, please input month(1-12)\n");
        scanf("%d", &month);
    }

    //设定days
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
    }

    printf("2023-%d has total %d days.", month, days);

    //计算每月第一天是星期几
    int y = 2023; char space[] = " " ;
    char a[] = "Mon.", b[] = "Tues." , c[] = "Wend.", h[] = "Thur.", e[] = "Fri.", f[] = "Stat." ,g[] = "Sun.";
    if((month==1)||(month==2))
    {
        month += 12;
        y -- ;
    }
    daySeqOfWeek = (1+2*month+3*(month+1)/5+y+y/4-y/100+y/400)%7;
    daySeqOfWeek += 1;
    printf("2023-%d-1 is No.%d day in that week.\n", month, daySeqOfWeek);

    //打印月历
    printf("%10s%10s%10s%10s%10s%10s%10s\n",a,b,c,h,e,f,g);
    int i, d = 1;
    for(i = 1; i < daySeqOfWeek; i++)
    {
        printf("%10s",space);
    }

    while(d <= days)
    {
        if(i % 7 == 0)
        {
            printf("%10d\n",d);
        }
        else
        {
            printf("%10d",d);
        }
        d ++;
        i ++;
    }

}