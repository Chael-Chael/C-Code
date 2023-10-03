#include <stdio.h>
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
    }

    return days;
}

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

int main()
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
    FirstDay = (week-1) * 7 + 1;
    LastDay = week *7;
    FirstDaySeq = getseq(FirstDay);
    LastDaySeq = getseq(LastDay);

    //Days to Month
    int month = 1, totaldays = 0, days = 31;
    while(FirstDay > totaldays)
    {
        totaldays += getmonthlength(month); 
        month += 1;
    }
    
    //Print Header
    char a[] = "Mon.", b[] = "Tues." , c[] = "Wend.", h[] = "Thur.", e[] = "Fri.", f[] = "Stat." ,g[] = "Sun.";
    printf("#w:%10s%10s%10s%10s%10s%10s%10s\n",a,b,c,h,e,f,g);
    printf("%2d:",week);

    //Print Week
    int i, d = 1;
    //
    if(month - 1 > 0 && month + 1 < 13)
    {
        for(i = 1; i < FirstDaySeq; i++)
        {
            printf("%2d-%2d", month-1, getmonthlength(month-1)-FirstDaySeq+i+1);
        }

        for()

        for(i = 1; i > LastDaySeq && i <= 7; i++)
        {
            printf("%2d-%2d", month+1, i);
        }   
    }
    else
    {
        
    }
    
    


    int y = 2023; char space[] = " " ;
    
    if((month==1)||(month==2))
    {
        month += 12;
        y -- ;
    }
    FirstDaySeq = 
    LastDaySeq = (1+2*month+3*(month+1)/5+y+y/4-y/100+y/400)%7;
     += 1;
    printf("No.%d week in 2023 starts from No.%d day to No.%d day.\n\n",week ,FirstDaySeq, 

    //打印月历
    
    


}