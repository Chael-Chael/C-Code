#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_LENGTH 12

void getRandArray(int array[], int length);
//get random array

void sortArray(int array[], int length);
//sort array using the insert algorithm

void displayArray(int array[], int length);
//display the array

int findSerials(int array[], int length);
//find the serials within the array

int main()
{
    srand( time(NULL) );
    //get seed

    int array[ARRAY_LENGTH] = {0};
    //initialize array
    int numberOfSerials = 0;

    getRandArray(array, ARRAY_LENGTH);
    displayArray(array, ARRAY_LENGTH);

    sortArray(array, ARRAY_LENGTH);
    //displayArray(array, ARRAY_LENGTH);

    numberOfSerials = findSerials(array, ARRAY_LENGTH);
    //count the number of serials

    printf("\nFind total %d pairs.", numberOfSerials);
    return 0;
}

void getRandArray(int array[], int length)
{
    int i, j;
    for (i = 0; i < length; i++)
    {
        array[i] = rand() % 100 + 1;
    }

    //check for repetition and regenerate
    for (i = 0; i < length; i++)
    {
        for (j = i + 1; j < length; j ++)
        {
            while (array[j] == array[i])
            {
                array[j] = rand() % 100 + 1;
            }
        }
    }
}

void sortArray(int array[], int length)
{
    int i, j, insert_value;
    for (i = 1; i < length; i++)
    {
        insert_value = array[i];
        for (j = i - 1; j >= 0 && array[j] > insert_value; j--)
        {
            array[j + 1] = array[j];
        }
        array[j + 1] = insert_value;
    }
}

int findSerials(int array[], int length)
{
    int i, j, k, commonDifference, numberOfSerials = 0;
    for (i = 0; i < length - 2; i ++)
    {
        for (j = i + 1; j < length - 1; j ++)
        {
            commonDifference = array[j] - array[i];
            for (k = j + 1; k < length; k ++)
            {
                if (array[j] + commonDifference == array[k])
                {
                    printf("(%d,%d,%d),", array[i], array[j], array[k]);
                    numberOfSerials ++;
                }  
            }
        }
    }
    //没有考虑越界问题
    printf("\b ");

    return numberOfSerials;
}

void displayArray(int array[], int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}