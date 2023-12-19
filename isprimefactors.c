#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int isPrimeNumber(int x);
void printPrimeFactors(int x);

int main()
{
    srand(time(NULL));
    int number[N], i;
    for (i = 0; i < N; i ++)
    {
        number[i] = 100 + rand() % 101;
    }


    int counter = 0;
    for (i = 0; i < N; i ++)
    {
        counter ++;
        if (isPrimeNumber(number[i]) == 0)
        {
            printf("(%d) %d is not a prime number. ", counter, number[i]);
            printPrimeFactors(number[i]);
        }
        else
        {
            printf("(%d) %d is a prime number.\n", counter, number[i]);
        }
    }
    
}

int isPrimeNumber(int x)
{
    int i;

    if (x < 2)
    {
        return 0;
    } 

    for (i = 2; i * i <= x; i ++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}  

void printPrimeFactors(int x)
{
    int i;
    printf("%d = ", x);

    //
    for (i = 2; i <= x; i ++)
    {
        while (x % i == 0)
        {
            printf("%d", i);
            x /= i;

            if (x != 1)
            {
                printf("*");
            }
        }
    }

    printf("\n");
}
/*
void printPrimeFactors(int x)
{
    int i;
    printf("%d = ", x);
    for (i = 2; i <= x; i ++)
    {
        if (x % i == 0)
        {
            printf("%d * ", i);
            x = x / i;
            i = 1;
        }
    }
    printf("\b\b  ");
    printf("\n");
}
*/