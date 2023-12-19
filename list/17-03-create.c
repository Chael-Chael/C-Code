#include <stdio.h>
#include <stdlib.h>

// create a new struct type named as Node
typedef struct node
{
    int value;
    struct node *next;
} Node;

// function to create the linked list with input numNode
// function return: the pointer to head node
Node* createLinkedList( int nodeNum );

// function to display the linked list with pointer to head
// function return: none
void displayLinkedList( Node *head );

int main()
{
    int nodeNum;
    printf("Please input the size of linked list: \n");
    scanf("%d", &nodeNum );
    
    if ( nodeNum < 1 )
    {
        printf("Invalid input. Program terminated.");
        exit(-100);
    }

    Node *listHead = createLinkedList( nodeNum );
    displayLinkedList( listHead );

    return 0;
}

/*
 * function name: createLinkedList
 * function arugment: int nodeNum, the number of nodes
 * function return: Node* head, the head pointer
 */
Node* createLinkedList( int nodeNum )
{
    // if the linked list is empty
    if ( nodeNum < 1 )
    {
        return NULL;
    }

    // create the head node of linked list
    Node *head = (Node *)malloc( sizeof(Node) );
    head->value = 10;
    head->next = NULL;

    Node *pPrevious = head, *pCurrent = NULL;
    for ( int i = 1 ; i < nodeNum; i ++ )
    {
        // create a new node
        pCurrent = (Node *)malloc( sizeof(Node) );
        pCurrent->value = ( i + 1 ) * 10;
        pCurrent->next = NULL;
        
        // link the new node and move to the next
        pPrevious->next = pCurrent;
        pPrevious = pCurrent;
    }

    return head;
}


/*
 * function name: displayLinkedList
 * function arugment: Node* head, the head pointer
 * function return: none
 */
void displayLinkedList( Node *head )
{
    // if the linked list is empty
    if ( head == NULL )
    {
        printf("this linked list empty\n");
        return ;
    }

    // navigate the linked list
    printf("this linked list is:\n");
    Node *pNode = NULL;
    int i = 1;
    for ( pNode = head; pNode != NULL ; pNode = pNode->next )
    {
         printf("[%02d] address=%p, value=%2d, next=%p \n",
                i++, pNode, pNode->value, pNode->next );
    }
    printf("\n");

    return ;
}
