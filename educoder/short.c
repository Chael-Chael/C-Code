#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROUNDS    6 
#define NUM_PLAYERS   8
#define TOTAL_VOTES   100

void setOneRoundVotes( int oneVotes[], const int numPlayers );

void getOneRoundRanks( const int oneVotes[], int oneRanks[], const int numPlayers);

void getPlayerTotalVotes( const int allVotes[][NUM_PLAYERS], int playerTotal[],
                        const int numRounds, const int numPlayers);

void displayOneRound( const int roundReq, const int oneVotes[], const int numPlayers );

void displayAllRounds( const int allVotes[][NUM_PLAYERS], const int numRounds, const int numPlayers );

int main( void )
{
    srand(time(NULL));

    int allVotes[NUM_ROUNDS][NUM_PLAYERS] = {{0}};
    int allRanks[NUM_ROUNDS][NUM_PLAYERS] = {{0}};
    int playerTotal[NUM_PLAYERS] = {0};
    int playerRank [NUM_PLAYERS] = {0};

    // generate random vote data and display it
    for ( int i = 0 ; i < NUM_ROUNDS; i ++ )
    {
        setOneRoundVotes( allVotes[i], NUM_PLAYERS );
    }
    //Why just one dimension array can be passed to the function?

    printf("\nThe votes results are:\n");
    displayAllRounds( allVotes, NUM_ROUNDS, NUM_PLAYERS );

    // calculate the corresponding rank data and display it
    for ( int i = 0; i < NUM_ROUNDS; i ++ )
    {
        getOneRoundRanks( allVotes[i], allRanks[i], NUM_PLAYERS );
    }
    printf("\nThe corresponding rank results are:\n");
    displayAllRounds( allRanks, NUM_ROUNDS, NUM_PLAYERS );
    // count the total votes for each player
    getPlayerTotalVotes( allVotes, playerTotal, NUM_ROUNDS, NUM_PLAYERS );
    printf("\nThe votes results of each player are:\n");
    displayOneRound( 0, playerTotal, NUM_PLAYERS );   
    // calculate the corresponding rank data and display it
    getOneRoundRanks( playerTotal, playerRank, NUM_PLAYERS ); 
    printf("\nThe corresponding rank results of each player are:\n");
    displayOneRound( 0, playerRank, NUM_PLAYERS );   
    return 0;
}

void displayOneRound( const int roundSeq, const int oneVotes[], const int numPlayers )
{
    int i; 
    if ( roundSeq > 0 ) 
    {
        printf("[%02d] ", roundSeq );
    }
    else
    {
        printf("     ");        
    }
    for ( i = 0; i < numPlayers; i ++ )
    {
        printf("%c=%2d, ", 'A' + i, oneVotes[i] );
    }

    /*debugging
    printf("\b\b ");
    int sum = 0;
    for ( i = 0; i < numPlayers; i ++ )
    {
        sum = sum + oneVotes[i];
    }
    printf(" sum=%d\n", sum);*/

    printf("\b\b  \n");
    return; 
}

void displayAllRounds( const int allVotes[][NUM_PLAYERS], const int numRounds, const int numPlayers)
{
    int i;
    for ( i = 0; i < numRounds; i ++ )
    {
        displayOneRound( i + 1, allVotes[i], numPlayers );
    }
    return;
}

void setOneRoundVotes(int oneVotes[], const int numPlayers)
{
   int i, totalVotes = 0;

   for (i = 0; i < numPlayers; i++)
   {
       //initialize oneVote
       oneVotes[i] = 1;
       totalVotes ++;
   }

   for (i = 0; i < numPlayers; i++)
   {
       if (totalVotes == 100)
       {
           //stop totalVotes from exceeding 100
           continue;
       }
       else
       {
            if (i == numPlayers - 1)
            {
                //ensure totalVotes is 100
                oneVotes[i] += 100 - totalVotes;
            }
            else
            {
                //generate random votes
                oneVotes[i] += rand() % (100 - totalVotes);
                totalVotes += oneVotes[i]; 
            }
        }
    }
}

void getOneRoundRanks( const int oneVotes[], int oneRanks[], const int numPlayers)
{
    int i, j;

    for (i = 0; i < numPlayers; i++)
    {
        oneRanks[i] = 1;

        //compare the votes of each player
        for (j = 0; j < numPlayers; j++)
        {
            if (oneVotes[j] > oneVotes[i])
            {
                oneRanks[i]++;
            }
        }
    }
}

void getPlayerTotalVotes (const int allVotes[][NUM_PLAYERS], int playerTotal[], const int numRounds, const int numPlayers)
{
   int i, j;

   for (i = 0; i < numPlayers; i ++)
   {
        playerTotal[i] = 0;

        int max = 0, min = 0;
        for (j = 0; j < numRounds; j ++)
        {
            if (allVotes[j][i] > max)
            {
                max = allVotes[j][i];
            }

            while (j < numRounds - 1)
            {
                if (allVotes[j][i] < allVotes[j+1][i])
                {
                    min = allVotes[j][i];
                }
                break;
            }
            

            playerTotal[i] += allVotes[j][i];
        }

        playerTotal[i] -= max;
        playerTotal[i] -= min;
   }
}
