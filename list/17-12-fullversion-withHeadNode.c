
#include <stdio.h>
#include <stdlib.h>

// structure of the node
typedef struct node
{
    int value;
    struct node * next;
} Node;

// function to get the head node of the linked list
// function return: the pointer to head node
Node* initLinkedList( void );

// function to create the linked list with input numNode
// function return: none
void createLinkedList( Node *head, int numNode );

// function to insert a new node, linked list sorted by node value
// function return: none
void insertNodeByValue( Node *head , int insertValue );

// function to find and delete a node by value, multiple node version
// function return: none
void deleteNodeByValue( Node *head , int deleteValue );

// function to reverse the linked list
// function return: none
void reverseLinkedList( Node *head );

// function to sort the linked list
// function return: none
void sortLinkedList( Node *head );

// function to free the memory of every node
// function return: none
void destroyLinkedList( Node *head );

// function to display the linked list with pointer to head
// function return: none
void displayLinkedList( Node *head );

// function to display the linked list with addr information
// function return: none
void displayLinkedListDetails( Node *head );


int main(void)
{
    Node *listHead = initLinkedList();
    // create a five node linked list for further program
    createLinkedList ( listHead, 5 );
    displayLinkedList( listHead );

    int choice = 0, input = 0;
    do
    {
        printf("Please input your choice (0=showAddr, 1=insert, "
               "2=delete, 3=reverse, 4=sort, 5=exit): ");
        scanf("%d", &choice );

        switch ( choice )
        {
            case 0:
                displayLinkedListDetails( listHead );
                continue;

            case 1:
                printf("Please input the insert value: ");
                scanf("%d", &input );
                insertNodeByValue( listHead, input );
                break;

            case 2:
                printf("Please input the value to delete: ");
                scanf("%d", &input );
                deleteNodeByValue( listHead, input ) ;
                break;

            case 3:
                reverseLinkedList( listHead ) ;
                break;

            case 4:
                sortLinkedList( listHead ) ;
                break;

            case 5:
                printf("Thank you for using this program. \n\n");
                continue;

            default:
                printf("Wrong input!\n\n");
                break;

        } // end of switch case

        displayLinkedList( listHead );

    } while ( choice!=5 );

    // destroy the linked list
    destroyLinkedList( listHead );

    return 0;
}

/*
 * function name: initLinkedList
 * function arugment: none
 * function return: Node* head, the head pointer
 */
Node* initLinkedList( void )
{
    // allocate memory for the head node
    Node* head = (Node *)malloc(sizeof(Node));
    head->value = -1;   // useless value, for memo only
    head->next = NULL;

    return head;
}

/*
 * function name: createLinkedList
 * function arugment:
 *          int numNode, the number of nodes
 * function return: Node* head, the head pointer
 */
void createLinkedList( Node *head, int numNode )
{
    // if the linked list is empty
    if ( numNode < 1 )
    {
        return;
    }

    int i;
    Node *pPrevious = head, *pCurrent = NULL;
    for ( i = 0 ; i < numNode; i ++ )
    {
        // create a new node
        pCurrent = malloc( sizeof(Node) );
        pCurrent->value = ( i + 1 ) * 10;
        pCurrent->next = NULL;

        // link the new node to the end of list
        pPrevious->next = pCurrent;
        // move to next node
        pPrevious = pCurrent;
    }
    return;
}


/*
 * function name: displayLinkedList
 * function arugment:
 *          Node* head, the head pointer
 * function return: none
 */
void displayLinkedList( Node *head )
{
    // if the linked list is empty
    if ( head->next == NULL )
    {
        printf("This linked list is empty. \n\n");
        return ;
    }

    // else, the linked list has at least one node
    printf("Current list:");
    for ( Node *pNode = head->next; pNode != NULL; pNode = pNode->next )
    {
         printf(" %2d -->", pNode->value );
    }
    printf("\b\b\b\b    \n\n");

}

/*
 * function name: displayLinkedListDetails
 * function arugment:
 *          Node* head, the head pointer
 * function return: none
 */
void displayLinkedListDetails( Node * head )
{
    if ( head->next == NULL )
    {
        printf("This linked list is empty.\n\n");
        return ;
    }

    // navigate the linked list
    printf("this linked list is:\n");
    int i = 1;
    for ( Node *pNode = head; pNode != NULL; pNode = pNode->next )
    {
         printf("[%02d] addr=%p, value=%3d, next=%p \n",
                i++, pNode, pNode->value, pNode->next );
    }
    printf("\n");
}


/*
 * function name: insertNodeByValue
 * function arugment:
 *    Node* head, the head pointer;
 *    int newValue, the insert value;
 * function return: new head
 */
void insertNodeByValue( Node *head, int newValue )
{
    // create a new node for this linked list
    Node *newNode ;
    newNode = (Node *)malloc( sizeof(Node) );
    newNode->value = newValue;
    newNode->next = NULL;

    if ( head->next == NULL )
    {
        // if the linked list is empty
        head->next = newNode;
        return;
    }
    
    int isFound = 0;
    Node *pPrevious = NULL, *pCurrent = NULL;
    // navigate the linked list, insert after head
    for ( pPrevious = head, pCurrent = pPrevious->next ;
          pCurrent != NULL ;
          pPrevious = pCurrent, pCurrent = pCurrent->next )
    {
        // to find the position to insert
        if ( newValue <= pCurrent->value )
        {
            // insert the node between the two
            pPrevious->next = newNode;
            newNode->next = pCurrent;
            isFound = 1;
            break;
        }
    }
    if ( isFound == 0 )
    {
        // insert into the last node
        pPrevious->next = newNode;
    }
    return;
}


/*
 * function name: deleteNodeByValue
 * function arugment:
 *    Node* head, the head pointer;
 *    int delValue, the delete value;
 * function return: new head
 */
void deleteNodeByValue( Node *head, int delValue )
{
    // if the linked list is empty
    if ( head->next == NULL )
    {
        printf("This linked list is empty. \n");
        return;
    }

    // otherwise, compare the rest nodes
    int isFound = 0;
    Node *pPrevious = NULL, *pCurrent = NULL;
    for ( pPrevious = head, pCurrent = pPrevious->next;
          pCurrent != NULL;
        )
    {
        if ( pCurrent->value == delValue )
        {
            // delete the node, free the memory
            pPrevious->next = pCurrent->next;
            free( pCurrent );
            isFound ++;
            pCurrent = pPrevious->next;
        }
        else
        {
            pPrevious = pCurrent;
            pCurrent = pCurrent->next;
        }
    } // end of for loop

    if ( isFound == 0 )
    {
        printf("The input value is not found. \n");
    }
    else
    {
        printf("Total %d node is/are deleted.\n", isFound );
    }
    return;
}

/*
 * function name: destroyLinkedList
 * function arugment:
 *    Node* head, the head pointer;
 * function return: none
 */
void destroyLinkedList( Node *head )
{
    // it is already empty
    if ( head->next == NULL )
    {
        return;
    }

    Node *pCurrent = head->next, *pPrevious = NULL;
    while ( pCurrent != NULL )
    {
        // store the addr to previous node
        pPrevious = pCurrent;
        // move to the next node
        pCurrent = pCurrent->next;
        // release memory for previous node
        free(pPrevious);
    }
    return ;
}


/*
 * function name: reverseLinkedList
 * function arugment:
 *    Node* head, the head pointer;
 * function return: Node* head
 */
void reverseLinkedList( Node *head )
{
    // if the linked list is empty
    //    no requirement for searching position
    if ( head->next == NULL )
    {
        return;
    }

    Node *pPrevious = head->next;
    Node *pCurrent  = pPrevious->next;
    Node *pNext = NULL;
    while ( pCurrent != NULL )
    {
        // store the next node
        pNext = pCurrent->next;
        // revsere the direction of pCurrent
        pCurrent->next = pPrevious;

        // move the two pointers to next
        pPrevious = pCurrent;
        pCurrent = pNext;
    }

    // the old head becomes the new tail of the list
    head->next->next = NULL;
    // return the old tail as the new head
    head->next = pPrevious;
    
    return ;
}


/*
 * function name: sortLinkedList
 * function arugment:
 *    Node* head, the head pointer;
 * function return: Node* head
 */
void sortLinkedList( Node *head )
{
    // no need for sorting
    if ( head->next == NULL || head->next->next == NULL )
    {
        return;
    }

    // prepare the sorted part
    Node *pEnd = head->next;

    Node *pPrevious = NULL;
    Node *pCurrent = NULL;
    Node *pNode = head->next->next;    // the next node to be checked
    while ( pNode != NULL )
    {   // navigate the sorted part of linked list
        pPrevious = head;
        pCurrent = head->next;
        while ( pCurrent != pNode && pNode->value >= pCurrent->value )
        {
            pCurrent = pCurrent->next;
            pPrevious = pPrevious->next;
        }

        if ( pCurrent != pNode )
        {   // find the position, insert pNode between pPrevious and pCurernt
            pEnd->next = pNode->next;
            pNode->next = pCurrent;
            pPrevious->next = pNode;
        }
        else
        {   // not find the position, extend the sorted part
            pEnd = pNode;
        }
        // update the next node to be checked
        pNode = pEnd->next;
    }

    return;
}


