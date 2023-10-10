#include <stdio.h>

int main(void)
{
    double pi, last;
    int t = 1, b = 1;
    for(int i=0;;i++)
    {
        pi += 4*t*1/(double)b;
        last = t*1/(double)b;
        b += 2;
        t = -t;
        printf("[%7d] 1/(4n-1) = %16.13f, pi = %17.15f\n", i, last, pi);
        
        if(last < 1E-7 && last > -1E-7)
        {
            break;
        }
    }
}