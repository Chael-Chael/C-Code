#include <stdio.h>

int main()
{
    printf("This program is to find all ");

    int mkun, fkun, skun, count = 0;
    for(mkun = 0; mkun <= 20; mkun++)
    {
        for(fkun = 0; fkun <= 33; fkun++)
        {
            for(skun = 0; skun <= 300; skun ++)
            {
                if(mkun*5 + fkun*3 + skun/3.0 == 100)
                {
                    count += 1;
                    printf("%d: rooster = %d, hen = %d, chick = %d\n", count, mkun, fkun, skun);
                }

            }
        }
    }
    return 0;
}