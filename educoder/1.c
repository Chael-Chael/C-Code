/* 
【程序意图】求两个升序数组的交集

【输入】两个随机升序数字集合

【输出】两个集合的交集 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE  8

// 产生一个升序的整数数组
void resetArray( int *array, const int size );

// 打印一个整数数组
void displayArray( int *array, const int size );

// 输入两个数组array1和array2，在函数中创建动态数组interSet，
// 通过函数返回值带回动态数组的首地址，通过interSize参数带回动态数组的元素数量
int *getIntersection( const int *array1, const int *array2, int *interSize);

int main( void )
{
    int SEED;
    scanf("%d", &SEED);
    srand(SEED);

    int array1[SIZE], array2[SIZE];
    resetArray(array1, SIZE );
    resetArray(array2, SIZE );

    printf("array1: ");
    displayArray(array1, SIZE );
    printf("array2: ");
    displayArray(array2, SIZE );

    int *interSet = NULL;
    int interSize = 0;
    interSet = getIntersection( array1, array2, &interSize );
    printf("intersection set: ");
    displayArray( interSet, interSize );
    free (interSet);

    return 0;
}

void resetArray( int *array,  int size)
{
    int *iPtr = NULL;
    int temp = 0;
    for ( iPtr = array ; iPtr < array + size; iPtr ++ )
    {
        temp += 1 + rand() % 5;
        *iPtr = temp;
    }
}

void displayArray( int *array,  int size)
{
    int *iPtr;
    for ( iPtr = array; iPtr < array + size; iPtr ++ )
    {
        printf("%02d ", *iPtr);
    }
    printf("\n");
}

int *getIntersection( const int *array1, const int *array2, int *interSize)
{
    // 预设一个动态数组，大小与SIZE相同
    int *interSet = (int *)malloc( sizeof(int) * SIZE );

    // 设置三个指针变量，分别遍历array1、array2和interSet
    int *p1 = (int *)array1;
    int *p2 = (int *)array2;
    int *p3 = interSet;

    // 通过指针的遍历获取交集的结果，不得再开辟其它内存区
    // -------------------------
    // your code start here








    // your code end here
    // -------------------------

    // 根据实际找到的交集元素数量，重新分配动态数组interSet的内存
    interSet = realloc( interSet, sizeof(int) * *interSize );

    return interSet;
}
