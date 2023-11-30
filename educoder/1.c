/* 
【程序意图】从一个数字、字母、符号混排的字符串中提取数字

【输入】一个随机字符串

【输出】从随机字符串里面提取的整数个数，以及整数结果的数组
    例如 “A>123x456” 中提取出来的2个整数，分别是 123 和 456 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_LENGTH   20

// 在字符数组str里面生成一个随机C风格字符串
// 返回值是字符串的实际有效长度（不计算'\0'）
int generateRandomStr( char *str, const int size );

// 从字符串str里面提取整数，存入numberList
// 返回值是找到的整数的个数
int getNumberFromString( char *str, const int length, int *numberList );


int main(void) 
{
    int SEED;
    scanf("%d", &SEED);
    srand(SEED);

    char str[MAX_STRING_LENGTH];
    int length = generateRandomStr( str, MAX_STRING_LENGTH );
    printf("Generated string with length %d: %s\n", length, str);

    int numberList[MAX_STRING_LENGTH];
    int numberCounter = getNumberFromString( str, length, numberList );
    printf("Found %d numbers: ", numberCounter );

    for ( int i = 0; i < numberCounter; i ++ )
    {
        printf("%d  ", numberList[i]);
    }
    printf("\n");

    return 0;
}


int generateRandomStr( char *str, const int size )
{
    int length = 10 + rand() % ( MAX_STRING_LENGTH - 10) ;
    char *p = NULL;
    for ( p = str; p < str + length; p ++ )
    {
        *p = '1' + rand() % ( 'Z' - '0' );
    }
    *p = '\0';
    return length;
}


int getNumberFromString( char *str, const int length, int *numberList )
{
    // 设置两个指针分别在str数组和numberList数组里面偏移
    char *cPtr = str;
    int *iPtr = numberList;

    // 通过指针的遍历获取结果，不得再开辟其它内存区
    // -------------------------
    // your code start here
    int num = 0;

    for(int i = 0; i < length; i++) {
        if (*(str+i) >= '0' && *(str+i) <= '9') {
            num = num * 10 + (*(str+i) - '0');
        } else {
            if (num != 0) {
                *iPtr = num;
                iPtr++;
                num = 0;
            }
        }
    }

    if (num != 0) {
        *iPtr = num;
        iPtr++;
    }

    return (iPtr - numberList);
}
