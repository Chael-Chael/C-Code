#include <stdio.h>
#include <stdlib.h>

void setMatrix(int *iMatrixAddr, int matrixSize);
void displayMatrix(int *iMatrixAddr, int matrixSize);

int main()
{
    int * iPtr;
    int size1 = 0, size2 = 0;

    printf("\nPlease input the size of the two matrix: ");
    scanf("%d %d", &size1, &size2);

    if (size1 <= 0 || size2 <= 0)
    {
        printf("\nInvalid input!\n");
        exit(-1);
    }

    //memory allocation for iPtr array
    iPtr = (int *)malloc(size1 * size1 * sizeof(int));
    setMatrix(iPtr, size1);
    displayMatrix(iPtr, size1);

    iPtr = (int *)realloc(iPtr, size2 * size2 * sizeof(int));
    setMatrix(iPtr, size2);
    displayMatrix(iPtr, size2);

    //memory free
    free(iPtr);

    return 0;
}

void setMatrix(int *iMatrixAddr, int matrixSize)
{
    int i = 0, j = 0;

    for (i = 0;i < matrixSize; i++)
    {
        for (j = 0; j < matrixSize; j ++)
        {
            *(iMatrixAddr + i * matrixSize + j) = i + j;
        }
    }
}

void displayMatrix(int *iMatrixAddr, int matrixSize)
{
    int i = 0, j = 0;

    for (i = 0; i < matrixSize; i++)
    {
        for (j = 0; j < matrixSize; j++)
        {
            printf("%5d", *(iMatrixAddr + i * matrixSize + j));
        }
        printf("\n");
    }
    printf("\n");
}   