#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct cube
{
    char name[7];
    int length;
    int width;
    int height;
    int volume;
} Cube;

void initRect(Cube *p);

void updateRects(Cube *p);

void printRects(Cube *p, int *rankArray);

void rankRects(Cube *p, int *rankArray);

void searchRectsByRank(Cube *p, int *rankArray, int rank);

int main()
{
    srand(time(NULL));

    Cube cuboid[10] = {0};

    // initialize the cuboid and update the volume
    for (int i = 0; i < 10; i++)
    {
        initRect(&cuboid[i]);
        updateRects(&cuboid[i]);
    }

    // rank the cuboid
    int rankArray[10] = {0};
    rankRects(cuboid, rankArray);
    for (int i = 0; i < 10; i++)
    {
        printRects(cuboid + i, rankArray + i);
    }

    // search the cuboid by rank
    int rank = 1 + rand() % 10;
    printf("The %d ranking rect is\n",rank);
    searchRectsByRank(cuboid, rankArray, rank);
    return 0;
}

void initRect(Cube *p)
{
    // set the name to rectXX
    strcpy(p->name, "rect");
    char digit1 = rand() % 10 + '0';
    char digit2 = rand() % 10 + '0';

    p->name[4] = digit1;
    p->name[5] = digit2;
    p->name[6] = '\0';

    p->length = rand() % 16 + 5;
    p->width = rand() % 16 + 5;
    p->height = rand() % 16 + 5;
}   

void updateRects(Cube *p)
{
    p->volume = p->length * p->width * p->height;
}

void rankRects(Cube *p, int *rankArray)
{
    for (int i = 0; i < 10; i ++)
    {
        *(rankArray+i) = 1;

        for (int j = 0; j < 10; j ++)
        {
            if ( (p+j)->volume > (p+i)->volume )
            {
                *(rankArray+i) += 1 ;
            }
        }
    }
}

void printRects(Cube *p, int *rankArraySeq)
{
    printf("Rank No.%d\n", *rankArraySeq);
    printf("Name:%s\n",p->name);
    printf("Length:%d\nWidth:%d\nHeight:%d\nVolume:%d\n\n",p->length,p->width,p->height,p->volume);
}

void searchRectsByRank(Cube *p, int *rankArray, int rank)
{
    int isFound = 0;
    for (int j = 0; j < 10; j ++)
    {
        if (rankArray[j] == rank)
        {
            printRects(p+j, rankArray+j);
            isFound = 1;
        }
    }
    // if no rect is found, print "No rect found"
    if (isFound == 0)
    {
        printf("No rect found\n");
    }
}