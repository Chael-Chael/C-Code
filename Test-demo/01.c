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

void searchRectsByRank(Cube *p, int *rankArraySeq);

int main()
{
    srand(time(NULL));

    //Cube cube1, cube2, cube3, cube4, cube5, cube6, cube7, cube8, cube9, cube10; 
    Cube cuboid[10] = {0};

    for (int i = 0; i < 10; i++)
    {
        initRect(&cuboid[i]);
        updateRects(&cuboid[i]);
    }

    int rankArray[10] = {0};
    int randRank = 1 + rand() % 10;

    printf("randRank by %d\n\n", randRank);\



    rankRects(cuboid, rankArray);

    for (int i = 0; i < 10; i ++)
    {
        if (randRank == rankArray[i])
        {
            printRects(&cuboid[i], &rankArray[i]);
            printf("\n");
        }
    }

    printf("Rank by order\n");
    searchRectsByRank(cuboid, rankArray);
    return 0;
}

void initRect(Cube *p)
{
    strcpy(p->name, "rect");
    char digit1 = rand() % 10 + '0';
    char digit2 = rand() % 10 + '0';

    p->name[4] = digit1;
    p->name[5] = digit2;
    p->name[6] = '\0';

    p->length = rand() % 15 + 5;
    p->width = rand() % 15 + 5;
    p->height = rand() % 15 + 5;
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

void searchRectsByRank(Cube *p, int *rankArray)
{
    for (int i = 1; i < 11; i ++)
    {
        for (int j = 0; j < 10; j ++)
        {
            if (rankArray[j] == i)
            {
                printRects(p+j, rankArray+j);
            }
        }
    }
}