#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define IP_ADDR_LENGTH 32

void setRandomIPAddr( char *ptr, int length);
//init the ip address
int isPrivateIPAddr( char *ptr, int length);
//judge the ip address is private or not
void displayBinaryIPAddr( char *ptr, int length);
//display the ip address in binary
void displayDecimalIPAddr( char *ptr, int length);
//display the ip address in decimal

int main()
{
    srand(time(NULL));

    char ip[IP_ADDR_LENGTH];

    setRandomIPAddr(ip, IP_ADDR_LENGTH);

    displayBinaryIPAddr(ip, IP_ADDR_LENGTH);

    displayDecimalIPAddr(ip, IP_ADDR_LENGTH);

    return 0;
}

void setRandomIPAddr( char *ptr, int length)
{
    for (int i = 0; i < length; i++)
    {
        *(ptr + i) = rand() % 2;
    }

    while (isPrivateIPAddr(ptr, length) == 1)
    {
        setRandomIPAddr(ptr, length);
    }
}

int isPrivateIPAddr( char *ptr, int length)
{
    int flag = 0;

    int address1 = 0;
    int address2 = 0;
    for (int i = 0; i < 8; i ++)
    {
        address1 += *(ptr + i) * pow(2, 7-i);
    }

    for (int i = 8; i < 16; i ++)
    {
        address2 += (*(ptr + i)) * pow(2, 15-i);
    }

    if (address1 == 192 && address2 == 168)
    {
        flag = 1;
        return flag;
    }

    int counterZero = 0;
    int counterOne = 0;
    for (int i = 0; i < length; i++)
    {
        if (*(ptr + i) == 0)
        {
            counterZero ++;
        }
        else
        {
            counterOne ++;
        }
    }

    if (counterZero == length || counterOne == length)
    {
        flag = 1;
    }

    return flag;
}

void displayBinaryIPAddr( char *ptr, int length)
{
    printf("Binary IP Address: ");
    int counter = 0;

    for (int i = 0; i < length; i++)
    {
        counter ++;
        printf("%d", *(ptr + i));
        
        if (counter % 8 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void displayDecimalIPAddr( char *ptr, int length)
{
    printf("Decimal IP Address: ");

    unsigned char decimalAddr[length/8];

    //convert binary to decimal
    for (int i = 1; i <= (length)/8; i ++)
    {
        *(decimalAddr + i - 1) = 0;
        for (int j = (i - 1)*8; j < (i*8); j ++)
        {
            *(decimalAddr + i - 1) += (*(ptr + j)) * pow(2, (i*8 - j - 1));
        }
    }
    
    //display decimal

    for (int i = 0; i < length/8; i++)
    {
        printf("%d", *(decimalAddr + i));
        printf(".");
    }
    printf("\b \n");
}