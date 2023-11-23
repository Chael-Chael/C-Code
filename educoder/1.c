// 文字处理

// 【问题描述】
// 对于给定的一段文字，将其解析到一个字符串数组(二维字符数组)中，
// 输出长度最长的单词，出现频次最多的单词

// 【编写要求】
// 1. 完成下列3个函数
// 2. 尽可能使用指针表达字符或者字符串，体会指针的用法

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_NUM   200
#define MAX_WORD_LEN   30

int parseMessage( char * message[], char (*words)[MAX_WORD_LEN], int seed);
int findLongestWord( char (*words)[MAX_WORD_LEN], int wordCounter );
void findHighFreqWord( char (*words)[MAX_WORD_LEN], int wordCounter,
         int *mostIndex, int *mostValue ); 
int getlength(char (*words)[MAX_WORD_LEN], int place);

int main()
{
    char* message[] = {"C is a general-purpose, high-level language that was originally developed by Dennis M. Ritchie to develop the UNIX operating system at Bell Labs. ",
    "C was originally first implemented on the DEC PDP-11 computer in 1972.",
    "In 1978, Brian Kernighan and Dennis Ritchie produced the first publicly available description of C, now known as the K&R standard.",
    "The UNIX operating system, the C compiler, and essentially all UNIX application programs have been written in C. ",
    "C programming is a general-purpose, procedural, imperative computer programming language developed in 1972 by Dennis M. Ritchie at the Bell Telephone Laboratories to develop the UNIX operating system. C is the most widely used computer language. It keeps fluctuating at number one scale of popularity along with the Java programming language, which is also equally popular and most widely used among modern software programmers."};
    
    char words[MAX_WORD_NUM][MAX_WORD_LEN] = {0};

    int seed;
    scanf("%d",&seed);


    int wordCounter = parseMessage( message, words, seed);
    printf("Total %d words are found.\n", wordCounter );

    int indexLong = findLongestWord( words, wordCounter );
    printf("The longest word is %s\n",  words[ indexLong ] );

    /*int counter = 0;
    for (int i = 0; i < wordCounter; i ++)
    {
        printf("%d,", getlength(words, i));
        counter ++;
    }
    printf("\n%d", counter);*/
    
    int indexMost, valueMost;
    findHighFreqWord( words, wordCounter, &indexMost, &valueMost );
    printf("The most frequently word is %s, it appears %d times\n", 
            words[ indexMost ], valueMost );

    return 0;
}

int parseMessage( char * message[], char (*words)[MAX_WORD_LEN], int seed )
{
    // -----------------------------
    // start of your source code
    //
    int wordCount = 0;
    int totalCount = 0;
    int k = seed;
    for (int i = 0, j = 0; message[k][i] != '\0'; i ++, j ++)

    {
        if (message[k][i] == ' ' )
        {
            wordCount ++;
            j = -1;
        }
        else if (message[k][i] == ',' || message[k][i] == '.')
        {
            wordCount ++;
            j = -1;
            i++; 
        }
        else
        {
            *(*(words+wordCount)+j) = message[k][i];
        }
    }
    totalCount += wordCount;
    wordCount = 0;
    return totalCount;
    //
    // end of your source code
    // -----------------------------
}

int findLongestWord( char (*words)[MAX_WORD_LEN] , int wordCounter )
{
    // -----------------------------
    // start of your source code
    //
    int indexLong = 0;
    int wordLength = 0;
    for (int k = 0; k < wordCounter; k ++)
    {
        int i;
        for (i = 0; i < MAX_WORD_NUM && *(*(words+k)+i) != 0; i++);
        if (i > wordLength)
        {
            indexLong = k;
            wordLength = i;
        }
    }
    return indexLong;

    //
    // end of your source code
    // -----------------------------
}

int getlength(char (*words)[MAX_WORD_LEN], int place)
{
    int i;
    for (i = 0; i < MAX_WORD_LEN && (*(*(words+place)+i) != 0) ; i++);
    return i;
}

void findHighFreqWord( char (*words)[MAX_WORD_LEN] , int wordCounter, int *mostIndex, int *mostValue )
{
    // -----------------------------
    // start of your source code
    //
    int isFound[MAX_WORD_LEN][2]={0};

    for (int k = 0; k < wordCounter - 1; k ++)
    {
        for (int j = k + 1; j < wordCounter; j ++)
        {
            if (getlength(words, k) == getlength(words, j))
            {
                for (int i = 0; i < MAX_WORD_NUM && *(*(words+k)+i) != 0 || *(*(words+j)+i) != 0; i++)
                {
                    if ( *(*(words+k)+i) == *(*(words+j)+i))
                    {
                        isFound[j][0] = 1;
                    }
                    else
                    {
                        isFound[j][0] = 0;
                        break;
                    }
                }

                if (isFound[j][0] == 1)
                {
                    isFound[k][1] ++;
                }
            }
        }
    }

    *mostIndex = 0;
    *mostValue = 0;

    for (int i = 0; i < MAX_WORD_LEN; i ++)
    {
        if ((isFound[i][1]+1) > *mostValue)
        {
            *mostIndex = i;
            *mostValue = isFound[i][1] + 1;
        }
    }
    //
    // end of your source code
    // -----------------------------
}
