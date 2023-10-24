#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int size = 51;
    int i;
    char string[size];

    printf("Enter a string with 50 characters: \n");

    for (i = 0; i < size - 1; i++)
    {
        scanf("%c", &string[i]);

        if (string[i] < 65 || (string[i] > 90 && string[i] < 97) || string[i] > 122)
        {
            printf("Error!");
            exit (0);
        }
        else
        {
            if (string[i] >= 65 && string[i] <= 90)
            {
                string[i] += 32;
            }
            else
            {
                string[i] -= 32;
            }
        }
    }

    for (i = 0; i < size - 1; i++)
    {
        printf("%c", string[i]);
    }

    return 0;
}