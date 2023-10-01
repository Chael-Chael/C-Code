#include <stdio.h>

int main()
{
    int count = 0, temp = 0, integer = 1;

    while(integer > 0)
    {
        printf("Please input positive integer, otherwise to stop: ");
        scanf("%d", &integer);
        if(integer > 0)
        {
            count += 1;
        }
        else
        {
            break;
        }

        if(integer > temp)
        {
            temp = integer;
        }
    }

    if(count < 2)
    {
        printf("No Valid Input");
        exit(0);
    }

    printf("The Max of %d input integer is: %d", count, temp);
}