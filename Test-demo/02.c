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

void displayBigReal(BigReal *p);

int main()
{
    srand(time(NULL));

    BigReal realArray[6] = {0};

    generateBigReal(realArray);
    printf("Before sort:\n"); 
    displayBigReal(realArray);

    /*
    BigReal real_1 = {"123.45600", 3, 6};
    BigReal real_2 = {"123.456", 3, 6};
    printf("compare result: %d\n", compareBigReal(&real_1, &real_2));
    BigReal real_3 = {"12.3456", 3, 6};
    BigReal real_4 = {"123.456", 3, 6};
    printf("compare result: %d\n", compareBigReal(&real_3, &real_4));
    BigReal real_5 = {"123.456", 3, 6};
    BigReal real_6 = {"123.456", 3, 6};
    printf("compare result: %d\n", compareBigReal(&real_5, &real_6));
    BigReal real_7 = {"123.4567", 3, 7};
    BigReal real_8 = {"123.456", 3, 6};
    printf("compare result: %d\n", compareBigReal(&real_7, &real_8));
    BigReal real_9 = {"123.456", 3, 6};
    BigReal real_10 = {"122.456", 3, 6};
    printf("compare result: %d\n", compareBigReal(&real_9, &real_10));
    */

    sortBigReals(realArray);
    printf("After sort:\n");
    displayBigReal(realArray);

    return 0;
}

BigReal *generateBigReal(BigReal *p)
{
    for (int i = 0; i < 6; i ++)
    {
        // set the length to 20-30
        (p+i)->length = 20 + rand() % 11;
        // allocate memory for the real number
        (p+i)->real = (char*) malloc( ( (p+i)->length + 2) * sizeof(char));
        // set the decimal point to 1-20
        (p+i)->decimal_point = 1 + rand() % 20;
        // set the first digit to 1-9
        (p+i)->real[0] = '1' + rand() % 9;
        // set the rest digits to 0-9
        for (int j = 1; j < (p+i)->length + 2; j++)
        {
            // set the decimal point
            if (j == (p+i)->decimal_point)
            {
                (p+i)->real[j] = '.';
            }
            else if (j == (p+i)->length + 1)
            {
                (p+i)->real[j] = '\0';
            }
            else{
                (p+i)->real[j] = '0' + rand() % 10;
            
            }
        }
    }

    return p;
}

int compareBigReal(BigReal *real_1, BigReal *real_2)
{
    // compare the decimal_point of the real number
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
        // get the min length of the real number
        int min_length = real_1->length > real_2->length ? real_2->length : real_1->length;
        for (int i = 0; i < min_length + 1; i ++)
        {
            if (real_1->real[i] > real_2->real[i])
            {
                return 1;
            }
            else if (real_1->real[i] < real_2->real[i])
            {
                return -1;
            }
        }

        if (real_1->length > real_2->length)
        {
            // check if the rest digits are all 0
            for (int j = min_length + 1; j < real_1->length + 1; j ++)
            {
                if (real_1->real[j] != '0')
                {
                    return 1;
                }
            }
            return 0;
        }
        else if (real_1->length < real_2->length)
        {
            // check if the rest digits are all 0
            for (int j = min_length + 1; j < real_2->length + 1; j ++)
            {
                if (real_2->real[j] != '0')
                {
                    return -1;
                }
            }
            return 0;
        }
        else
        {
            return 0;
        }
    }
}

void sortBigReals(BigReal *p)
{
    int i, j, minIndex;
    BigReal temp;
    // selection sort
    for (i = 0; i < 6 - 1; i++)
    {
        minIndex = i;

        for (j = i + 1; j < 6; j++)
        {
            if (compareBigReal(p + j, p + minIndex) == -1)
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            // swap the real number
            temp = *(p + i);
            *(p + i) = *(p + minIndex);
            *(p + minIndex) = temp;
        }
    }
}

void displayBigReal(BigReal *p)
{
    for (int i = 0; i < 6; i ++)
    {
        printf("%s\n", (p+i)->real);
    }
}