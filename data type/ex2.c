#include <stdio.h>

int main(void)
{
    unsigned long int n1 = 1, n2 = 1, temp;

    for(int i = 1; i <= 90; i++)
    {
        printf("[%3d] fn = %25lu\n", i, n1);
        temp = n1;
        n1 = n2;
        n2 += temp;
    }

}