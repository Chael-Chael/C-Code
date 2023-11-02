#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HOUR_RANGE     12
#define MINUTE_RANGE   60
#define SECOND_RANGE   60
#define tSize   24

typedef struct
{
	int hour;
	int min;
	int sec;
	int totalSec;
} Time;

// function to generate random time array
void generateTimeArray(Time tArray[], const int size);

// function to display time array
void displayTimeArray(const Time tArray[], const int size);

// function to sort time array, using insert sorting
void sortTimeArray(Time tArray[], const int size);

// function to count time array according to hours, and return max index
int countTimeArray(const Time tArray[], int hourCounter[], const int size);

// function to display coutner array
void displayTimeCounter(const int hourCounter[]);


int main(void)
{
	int SEED;
	scanf("%d", &SEED);
	srand(SEED);

	//const int tSize = 24;
	Time timeArray[tSize];
	int hourCounter[HOUR_RANGE] = { 0 };

	printf("\nGenerate %d Time elements:\n", tSize);
	generateTimeArray(timeArray, tSize);
	displayTimeArray(timeArray, tSize);

	printf("\nSort %d Time elements:\n", tSize);
	sortTimeArray(timeArray, tSize);
	displayTimeArray(timeArray, tSize);

	printf("\nCount %d Time elements:\n", tSize);
	int maxCounterIndex = countTimeArray(timeArray, hourCounter, tSize);
	displayTimeCounter(hourCounter);
	printf("The hour with max generated time is hour %d, with %d times.\n",
		maxCounterIndex, hourCounter[maxCounterIndex]);

	return 0;

}


void generateTimeArray(Time tArray[], const int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		tArray[i].hour = rand() % HOUR_RANGE;
		tArray[i].min = rand() % MINUTE_RANGE;
		tArray[i].sec = rand() % SECOND_RANGE;
		tArray[i].totalSec = tArray[i].hour * 3600
			+ tArray[i].min * 60 + tArray[i].sec;
	}

	return;
}


void displayTimeArray(const Time tArray[], const int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("[%2d] %02d:%02d:%02d\n",
			i, tArray[i].hour, tArray[i].min, tArray[i].sec);
	}

	return;
}


void displayTimeCounter(const int hourCounter[])
{
	int i;
	for (i = 0; i < HOUR_RANGE; i++)
	{
		printf("[%02d:00:00 ~ %02d:%02d:%02d]   %2d\n",
			i, i, MINUTE_RANGE - 1, SECOND_RANGE - 1,
			hourCounter[i]);
	}

	return;
}


// **********************************************
// << Your source code starts here >>
//


// function to sort time array
void sortTimeArray(Time tArray[], const int size)
{
	int i, j, insert_value;
    Time insert_array;
    for (i = 1; i < size; i ++)
    {
        insert_value = tArray[i].totalSec;
        insert_array = tArray[i];
        for (j = i - 1; (j >= 0) && (tArray[j].totalSec > insert_value); j --)
        {
            tArray[j+1] = tArray[j];
        }
        if (j != i - 1)
        {
            tArray[j+1] = insert_array; 
        }
    }
}

// function to count time array according to hours, and return max index
int countTimeArray(const Time tArray[], int hourCounter[], const int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < HOUR_RANGE; j++)
        {
            if (tArray[i].hour == j)
            {
                hourCounter[j]++;
                break;
            }
        }
    }

    int max = 0;
    int maxelement = hourCounter[0];
    for (j = 0; j < HOUR_RANGE - 1; j++)
    {
        if (hourCounter[j+1] > maxelement)
        {
            max = j+1;
            maxelement = hourCounter[j+1];
        }
    }

    return max;

//
// << Your source code stops here >>
// **********************************************