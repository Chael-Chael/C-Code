#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_NUM 200
#define MAX_WORD_LEN 30

// function to parse the message
// return the found number of words
int parseMessage(char message[], char *wordList);


int main()
{

    char message[1000] ;
    gets(message);

    char wordList[MAX_WORD_NUM][MAX_WORD_LEN] = {NULL};
    printf("Orignal msg is: %s \n\n", message);

    char *pointer = wordList;
    int wCounter = parseMessage(message, pointer);

    for (int i = 0; i < wCounter; i++)
    {
        
        printf("%s\n", wordList[i]);
    }

    printf("\nFind total %d words.\n\n", wCounter);

    return 0;
}


// **********************************************
// << Your source code starts here >>
//
int parseMessage(char message[], char *wordList)
{
    int *ptr = message;
    int counter = 0;
    while (*ptr != '\0')
    {
        if (*ptr == ' ')
        {
            counter ++;
        }
        else
        {
            *wordList = *ptr;
            wordList++;
        }
        ptr ++;
    }

    return counter;
}
//
// << Your source code stops here >>
// **********************************************