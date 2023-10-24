
//Converting decimal numbers to binary number and hexadecimal number

#include <stdio.h>
#include <math.h>

// 
// constant to express the range
#define BIT_WIDTH   32

void printBinary( unsigned int decNum );
static int bitWidth; 

int main( )
{
    unsigned int decNum;
    unsigned int decMax = (unsigned int) pow(2, BIT_WIDTH ) - 1; 
    printf("\nPlease enter one positive decimal number (1~%u):\n", decMax );
    scanf("%u", &decNum);

    if ( decNum > decMax )
    {
        printf("Input overflow. Program terminated.\n\n");
        return 200;
    }

    printf("The corresponding binary number is:\n" );
    printBinary( decNum );
    printf("\n\n");

    return 0;
}


// **********************************************
// << Your source code starts here >>
//
void printBinary( unsigned int decNum)
{
    int out, i;
    for (i = 0; i < BIT_WIDTH; i++)
    {
        printf(".");
        
        if (decNum == 1)
        {
            out = 1;
            printf("\b\b%d", out);
        } 
        else
        {
            return printBinary(decNum/2);
            printf ("\b\b%d", decNum%2);
        }

        bitWidth ++;

        if (bitWidth % 4 == 0)
        {
            printf("\b  ");
        }
    }
    

    


}
//
// << Your source code stops here >>
// **********************************************