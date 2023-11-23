#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_IP   10
#define NUM_HEX_SEG  8
#define HEX_SEG_SIZE 4

typedef struct{
    char ip[NUM_HEX_SEG][HEX_SEG_SIZE];
    int  isZeroSeg[NUM_HEX_SEG];
} IPv6;

//get random IP address
void setRandomIPv6Addr(char (*)[HEX_SEG_SIZE]);
//update the compression info for IP address
void getZeroSegs(const char (* const ipPtr)[HEX_SEG_SIZE], int * isZeroPtr);
//display the original hex form of IPv6 address
void displayOriginalIPv6Addr(const IPv6 * const ipPtr);
//display the compressed hex form of IPv6 address
void displayCompressedIPv6Addr(const IPv6 * const ipPtr);
int main( void )
{
    srand( time(NULL) );
    IPv6 ipArray[NUM_IP];
    IPv6 *ipPtr = NULL;
    for ( ipPtr = ipArray; ipPtr < ipArray + NUM_IP; ipPtr ++ )
    {
        printf("\nNo.%d IPv6 address:\n", ipPtr - ipArray );
        setRandomIPv6Addr(ipPtr->ip);
        displayOriginalIPv6Addr(ipPtr);
        getZeroSegs(ipPtr->ip, ipPtr->isZeroSeg);
        /*printf("\n");
        for (int i = 0; i < NUM_HEX_SEG; i ++)
        {
            printf("%d ", *((ipPtr->isZeroSeg)+i) );
        }*/
        displayCompressedIPv6Addr(ipPtr);
    }
    return 0;
}
void setRandomIPv6Addr(char (*ip)[HEX_SEG_SIZE])
{
    int i, j;
    int temp;
    for ( i = 0 ; i < NUM_HEX_SEG; i ++ )
    {
        if ( (rand() % 2) == 1 )
        {
            for ( j = 0; j < HEX_SEG_SIZE; j ++ )
            {
                ip[i][j] = '0';    
            }
        }
        else 
        {
            for ( j = 0; j < HEX_SEG_SIZE; j ++ )
            {
                temp = rand() % 16;
                if ( temp < 10 )
                {
                    ip[i][j] = '0' + temp;
                }    
                else if ( temp < 16 )
                {
                    ip[i][j] = 'A' + temp - 10;
                }
            }            
        }
    }
    return;
}

void displayOriginalIPv6Addr ( const IPv6 * const ipPtr )
{
    int i, j;
    for ( i = 0; i < NUM_HEX_SEG; i ++)
    {
        for (j = 0; j < HEX_SEG_SIZE; j ++)
        {
            printf("%c", ipPtr->ip[i][j]);
        }
        printf(":");
    }
    printf("\b ");
}

void getZeroSegs(const char (* const ipPtr)[HEX_SEG_SIZE], int * isZeroPtr)
{
    for (int i = 0; i < NUM_HEX_SEG; i ++)
    {
        int counter = 0;
        for (int j = 0; j < HEX_SEG_SIZE; j ++)
        {
            if ( *(*(ipPtr+i)+j) == '0')
            {
                counter ++;
            }
        }

        if (counter == HEX_SEG_SIZE)
        {
            * isZeroPtr = 1;
        }
        else
        {
            * isZeroPtr = 0;
        }
        isZeroPtr ++;
    }
}

void getZeroNum (const IPv6 * const ipPtr, int * ptr)
{
    for (int i = 0; i < NUM_HEX_SEG; )
    {
        while(*((ipPtr->isZeroSeg)+i) == 0)
        {
            i ++;
        }

        for (int j = i + 1; j < NUM_HEX_SEG; j ++)
        {
            if ( *((ipPtr->isZeroSeg)+j) == 1 && *((ipPtr->isZeroSeg)+j-1) == 1 )
            {
                *(ptr + i) += 1;
            }
        }
        i ++;
    }
}

void displayCompressedIPv6Addr(const IPv6 * const ipPtr) 
{
    int i, j;
    int ZeroNum[NUM_HEX_SEG] = {0};
    int *ptr = ZeroNum;

    for ( i = 0; i < NUM_HEX_SEG; )
    {
        for (j = 0; j < HEX_SEG_SIZE; )
        {
            if (*((ipPtr->isZeroSeg)+i) == 0)
            {
                while( *(*((ipPtr->ip)+i)+j) == '0')
                {
                    j ++;
                }
                printf("%c", ipPtr->ip[i][j]);
                j ++;
            }

            if (*((ipPtr->isZeroSeg)+i) == 1)
            {
                getZeroNum(ipPtr, ptr);
                int initPlace = 0;

                for (int x = 0; x < NUM_HEX_SEG; x++)
                {
                    if (*(ptr+x) != 0)
                    {
                        if (*(ptr+x) > *(ptr+initPlace))
                        {
                            initPlace = x;
                        }
                    }
                }

                if (initPlace == 0 && *(ptr+initPlace) != 0 && i == 0)
                {
                    printf(":");
                    i += *(ptr+initPlace);
                }
                else if (*(ptr+initPlace) != 0 && i == initPlace)
                {
                    i += *(ptr+initPlace);
                }
                else
                {
                    printf("0");
                }
                break;
            }
        }
        printf(":");
        i ++;
    }
    printf("\b ");
}

