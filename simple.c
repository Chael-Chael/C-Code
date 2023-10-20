#include <stdio.h>

int main()
{
    int array[5], i, sum = 0;

    printf ("Please input 5 integer values:\n");
    for (i = 0; i < 5; i++)
    { 
        scanf("%d", &array[i]);
        sum += array[i];
    }
    
    int max = array[0];
    int seq;
    for (i = 1; i < 5; i++)
    {
        if (array[i] > max)
        {
            max= array[i];
            seq = i;
        }
    }

    printf("The max value array[%d] = %d\n", seq, max);
    printf("The sum is %d, ", sum);
    printf("the average is %.2f ", (float)sum/5);

    return 0;
}