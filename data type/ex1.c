#include<stdio.h>

void displaybits(unsigned int value)
{

    unsigned int temp,c;
    temp =value;
    unsigned int displaymask = 1<<7;
    for(c = 1;c<=8;c++)
    {
        putchar(value & displaymask?'1':'0');
        value <<=1;
    }
    value = temp;
}

int main(void)
{
    unsigned int number;
   


    printf("\n%8s%10s%10s%10s\n","binary","octal","decimal","hex");

    for(number=0;number<=40;number++)
    {
        displaybits(number);
        printf("%10o",number);
        printf("%10d",number);
        printf("%10x",number);
        printf("\n");

    }
    printf("\n\n");

}