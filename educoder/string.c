#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 30

typedef struct {
    char content[N];
    int length;
} Str;

Str getRandString (int length);

Str getStringIntersection (Str s1, Str s2);

Str getStringUnion (Str s1, Str s2);

int compareTwoStrByDistinctLetters (Str s1, Str s2);

void displayStr (Str s);

//Str inputStr ();

int main()
{
    srand(time(NULL));

    //get random string
    Str s1 = getRandString(rand() % (N/2-1) + 1);
    Str s2 = getRandString(rand() % (N/2-1) + 1);
    //Str s1 = inputStr();
    //Str s2 = inputStr();

    printf("%-22s", "Generate string1 as:");
    displayStr(s1);
    printf("\n%-22s", "Generate string2 as:");
    displayStr(s2);

    //get intersection and union
    Str intersec = getStringIntersection(s1, s2);
    Str uni = getStringUnion(s1, s2);
    printf("\n%-22s", "Their intersection is:");
    displayStr(intersec);
    printf("\n%-22s", "Their union is:");
    displayStr(uni);


    //compare two string by distinct letters
    int result = compareTwoStrByDistinctLetters(s1, s2);
    if (result == 1)
    {
        printf("\nString 1 has more distinct letters.");
    }
    else if (result == -1)
    {
        printf("\nString 2 has more distinct letters.");
    }
    else
    {
        printf("\nString 1 and string 2 have the same number of distinct letters.");
    }
}

void displayStr (Str s)
{
    for (int i = 0; i < N; i++)
    {
        printf("%c", s.content[i]);
    }
    printf(" (length= %d)", s.length);
}

Str getRandString (int length)
{
    Str s;
    s.length = length;

    for (int i = 0; i < length; i++)
    {
        int Caps = rand() % 2;
        if (Caps)
        {
            s.content[i] = rand() % 26 + 'A';
        }
        else
        {
            s.content[i] = rand() % 26 + 'a';
        }
    }

    for (int j = length; j < N; j++)
    {
        s.content[j] = '_';
    }

    return s;
}

Str getStringIntersection (Str s1, Str s2)
{
    Str intersec;
    int lengthCount = 0;

    for (int i = 0; i < s1.length; i++)
    {
        if (lengthCount == 0)
        {
            int isFound = 0;
            for (int j = 0; j < s2.length; j++)
            {
                if (isFound == 1)
                {
                    break;
                }
                if (s1.content[i] == s2.content[j])
                {
                    intersec.content[lengthCount] = s1.content[i];
                    lengthCount ++;
                    isFound = 1;
                }
            }
        }

        for (int k = 0; k < lengthCount; k++)
        {
            if (s1.content[i] == intersec.content[k])
            {
                break;
            }
            else if (k == lengthCount - 1)
            {
                int isFound = 0;
                for (int j = 0; j < s2.length; j++)
                {
                    if (isFound == 1)
                    {
                        break;
                    }
                    if (s1.content[i] == s2.content[j])
                    {
                        intersec.content[lengthCount] = s1.content[i];
                        lengthCount ++;
                        isFound = 1;
                    }
                }
            }
            else
            {
                continue;
            }
        }
    }

    for (int j = lengthCount; j < N; j++)
    {
        intersec.content[j] = '_';
    }

    intersec.length = lengthCount;

    return intersec;
}

Str getStringUnion (Str s1, Str s2)
{
    Str uni;

    int lengthCount = 0;

    Str intersec = getStringIntersection (s1, s2);

    uni.content[0] = s1.content[0];
    lengthCount ++;

    for (int i = 0; i < s1.length; i ++)
    {
        for (int j = 0; j < lengthCount; j ++)
        {
            if (s1.content[i] == uni.content[j])
            {
                break;
            }
            else if (j == lengthCount - 1)
            {
                uni.content[lengthCount] = s1.content[i];
                lengthCount ++;
            }
            else
            {
                continue;
            }
        }
    }

    for (int i = 0; i < s2.length; i ++)
    {
        for (int k = 0; k < intersec.length; k ++)
        {
            if (s2.content[i] == intersec.content[k])
            {
                break;
            }
            else if (k == intersec.length - 1)
            {
                for (int j = 0; j < lengthCount; j ++)
                {
                    if (s2.content[i] == uni.content[j])
                    {
                        break;
                    }
                    else if (j == lengthCount - 1)
                    {
                        uni.content[lengthCount] = s2.content[i];
                        lengthCount ++;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            else
            {
                continue;
            }
        }
    }

    for (int j = lengthCount; j < N; j++)
    {
        uni.content[j] = '_';
    }

    uni.length = lengthCount;
    return uni;
}

int compareTwoStrByDistinctLetters (Str s1, Str s2)
{
    int distinctCount1 = 0;
    int distinctCount2 = 0;

    for (int i = 0; i < s1.length; i++)
    {
        int similarcount = 0;
        for (int j = 0; j < s1.length; j++)
        {
            if (j == i)
            {
                continue;
            }

            if (s1.content[j] == s1.content[i])
            {
                similarcount ++;
                break;
            }
        }

        if (similarcount == 0)
        {
            distinctCount1++;
        }
    }

    for (int i = 0; i < s2.length; i++)
    {
        int similarcount = 0;
        for (int j = 0; j < s2.length; j++)
        {
            if (j == i)
            {
                continue;
            }
            
            if (s2.content[j] == s2.content[i])
            {
                similarcount ++;
                break;
            }
        }
        if (similarcount == 0)
        {
            distinctCount2++;
        }
    }

    printf("\nString 1 has %d distinct letters.", distinctCount1);
    printf("\nString 2 has %d distinct letters.", distinctCount2);

    if (distinctCount1 > distinctCount2)
    {
        return 1;
    }
    else if (distinctCount1 < distinctCount2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}