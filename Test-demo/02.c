#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct big_real
{
    char *real;
    int decimal_point;
    int length;
} BigReal;

BigReal *generateBigReal(BigReal *p);

int compareBigReal(BigReal *real_1, BigReal *real_2);

void sortBigReals(BigReal *realArray);

int main()
{
    srand(time(NULL));

    BigReal realArray[6] = {0};

    generateBigReal(BigReal *p);


    return 0;
}

BigReal *generateBigReal(BigReal *p)
{
    for (int i = 0; i < 6; i ++)
    {
        (p+i)->length = 1 + 20 + rand() % 10;

        (p+i)->real = (char*) malloc( (p+i)->length * sizeof(char));

        (p+i)->decimal_point = 1 + rand() % 20;

        (p+i)->real[0] = '1' + rand() % 9;
        for (int j = 1; j < (p+i)->length; j++)
        {
            if (j == (p+i)->decimal_point - 1)
            {
                (p+i)->real[j] = '.';
            }
            else
            {
                (p+i)->real[j] = '0' + rand() % 10;
            }
        }
    }

    return p;
}

int compareBigReal(BigReal *real_1, BigReal *real_2)
{
    if (real_1->decimal_point > real_2->decimal_point)
    {
        return 1;
    }
    else if (real_1->decimal_point < real_2->decimal_point)
    {
        return -1;
    }
    else
    {
        double num_1 = 0.0, num_2 = 0.0;
        for (int i = 0; i < real_1->length; i ++)
        {
            int power = real_1->decimal_point - 2;

            if (i == real_1->decimal_point - 1)
            {
                power = -1;
                continue;
            }

            num_1 += ((real_1->real[i]) - '0') * (10, power);
            power --;
        }

        for (int j = 0; j < real_2->decimal_point; j ++)
        {
            int power = real_2->decimal_point - 2;

            if (j == real_2->decimal_point - 1)
            {
                power = -1;
                continue;
            }

            num_2 += ((real_2->real[i]) - '0') * (10, power);
            power --;
        }
    }
}

void sortBigReals(BigReal *p)
{

}
