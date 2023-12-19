#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM 8

typedef struct node
{
    int value;
    struct node * next;
} Node;

void getRandArray( int* array, int num );
int getPrimeFactors( int num, int* primearray);
Node* createPrimeList(int *array, int num);
Node* sortLinkedList( Node *head );
void displayLinkedList( Node *head, FILE *filePointer );

int main()
{
    FILE *filePointer;
    const char *filepath = "C:/Users/huawei/Downloads/output_05.txt";
    filePointer = fopen(filepath, "a");

    if (filePointer == NULL) {
        fprintf(stderr, "无法打开文件\n");
        return 1;
    }

    srand(time(NULL));

    int randArray[NUM];
    int *p = randArray;
    Node *head;
    
    /*
    for (int i = 0; i < 5; i++)
    {
        fprintf(filePointer, "Test %d:\n", i + 1);
        getRandArray( p, NUM );

        fprintf(filePointer, "The random array of numbers is: ");

        for (int j = 0; j < NUM; j++)
        {
            fprintf(filePointer, "%d ", *(p + j));
        }
        fprintf(filePointer, "\n");
        head = createPrimeList( p, NUM);
        head = sortLinkedList( head );
        displayLinkedList(head, filePointer);
    }
    */
    
    
    
    getRandArray( p, NUM );

    fprintf(filePointer, "The random array of numbers is: ");

    for (int j = 0; j < NUM; j++)
    {
        fprintf(filePointer, "%d ", *(p + j));
    }
    fprintf(filePointer, "\n");
    head = createPrimeList( p, NUM);
    head = sortLinkedList( head );
    displayLinkedList(head, filePointer);
    

    fclose(filePointer);
    return 0;
}

void getRandArray( int *array, int num )
{
    for ( int i = 0; i < num; i ++ )
    {
        *(array + i) = rand() % 100 + 100;
    }
}

int getPrimeFactors( int num, int* primearray)
{
    int i = 0;
    printf("%d = ", num);
    for (int j = 2; j <= num; j ++)
    {
        if ( num % j == 0 )
        {
            *(primearray + i) = j;
            printf("%d * ", j);
            num = num / j;
            j = 1;
            i ++;
        }
    }

    printf("\b\b  ");
    printf("\n");
    return i;
}

Node* createPrimeList(int *array, int num)
{
    int nodeNum = 0;
    int primearray[80];
    for (int i = 0; i < num; i++)
    {
        nodeNum += getPrimeFactors( *(array+i), primearray + nodeNum);
    }
    
    // create the head node of linked list
    Node *head = (Node *)malloc( sizeof(Node) );
    head->value = primearray[0];
    head->next = NULL;

    Node *pPrevious = head, *pCurrent = NULL;
    for ( int i = 1 ; i < nodeNum; i ++ )
    {
        // create a new node
        pCurrent = (Node *)malloc( sizeof(Node) );
        pCurrent->value = primearray[i];
        pCurrent->next = NULL;
        
        // link the new node and move to the next
        pPrevious->next = pCurrent;
        pPrevious = pCurrent;
    }

    return head;
}

Node* sortLinkedList( Node *head )
{
    // no need for sorting
    if ( head == NULL || head->next == NULL )
    {
        return head;
    }
    // introduce a Start node for sorting, prepare the sorted part
    Node *pStart = (Node *) malloc( sizeof (Node ));
    Node *pEnd = head;
    pStart->next = head;
    
    Node *pPrevious = NULL;      // the dual pointers for navigation
    Node *pCurrent = NULL;       // the dual pointers for navigation
    Node *pNode = head->next;    // the next node to be checked
    while ( pNode != NULL )
    {   // navigate the sorted part of linked list
        pPrevious = pStart;
        pCurrent = pStart->next;
        while ( pCurrent != pNode && pNode->value >= pCurrent->value )
        {
            pCurrent = pCurrent->next;
            pPrevious = pPrevious->next;
        }
        // check whether the position of pNode is found
        if ( pCurrent != pNode )
        {   // find the position, insert pNode between pPrevious and pCurernt
            pEnd->next = pNode->next;
            pNode->next = pCurrent;
            pPrevious->next = pNode;
        }
        else
        {
            // not find the position, extend the sorted part
            pEnd = pNode;
        }
        // update the next node to be checked
        pNode = pEnd->next;
    }
    
    // delete the assisted Start node
    head = pStart->next;
    free(pStart);
    
    return head;
}

void displayLinkedList( Node *head, FILE *filePointer )
{
    if ( head == NULL )
    {
        printf("this linked list empty\n");
        fprintf(filePointer, "this linked list empty\n");
        return ;
    }

    // navigate the linked list
    int numCount = 1;
    fprintf(filePointer, "The prime factors are: ");
    for ( Node *pNode = head; pNode != NULL; pNode = pNode->next )
    {
        fprintf(filePointer, "%d ", pNode->value);
    }
    fprintf(filePointer, "\n");
        
    for ( Node *pNode = head; pNode != NULL; pNode = pNode->next )
    {
        if (pNode->next == NULL)
        {
            printf("%d appeared %d times\n", pNode->value, numCount);
            fprintf(filePointer, "%d appeared %d times\n", pNode->value, numCount);
            break;
        }
        else
        {
            if ( (pNode->next)->value != pNode->value)
            {
                printf("%d appeared %d times\n", pNode->value, numCount);
                fprintf(filePointer, "%d appeared %d times\n", pNode->value, numCount);
                numCount = 1;
            }
            else
            {
                numCount ++;
        }
        }
        
        //printf("%d *", pNode->value);
        //fprintf(filePointer, "%d ", pNode->value);
    }
    printf("\b\n\n");
    fprintf(filePointer, "\n\n");
}

