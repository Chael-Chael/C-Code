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

// function to display the linked list with addr information
// function return: none
void displayLinkedListDetails( Node *head );

// function to insert a new node, linked list sorted by node value
// function return: the pointer to head node
Node* insertNodeByValue( Node *head , int insertValue );

// function to find and delete a node by value
// function return: the pointer to head node
Node* deleteNodeByValue( Node *head , int deleteValue );

// function to free the memory of every node
// function return: none
void destroyLinkedList( Node *head );

// function to find and delete a node by value
// function return: the pointer to head node
Node* deleteMultiNodeByValue( Node *head , int deleteValue );

// function to reverse the linked list
// function return: the pointer to head node
Node* reverseLinkedList( Node *head );

int main(void)
{
    Node * listHead = createLinkedList( 4 );
    // the linked list is {10, 20, 30, 40};
    displayLinkedList( listHead );

    printf("reserve the linked list:\n");
    listHead = reverseLinkedList( listHead );
    displayLinkedList( listHead );

    destroyLinkedList( listHead );

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
 * function arugment:
 *          Node* head, the head pointer
 * function return: none
 */
void displayLinkedList( Node *head )
{
    if ( head == NULL )
    {
        printf("This linked list is empty. \n\n");
        return ;
    }

    // navigate the linked list
    printf("Current list: ");
    for ( Node *pNode = head; pNode != NULL; pNode = pNode->next )
    {
         printf(" %2d -->", pNode->value );
    }
    printf("\b\b\b\b       \n\n");
}

/*
 * function name: displayLinkedListDetails
 * function arugment:
 *          Node* head, the head pointer
 * function return: none
 */
void displayLinkedListDetails( Node * head )
{
    if ( head == NULL )
    {
        printf("This linked list is empty.\n\n");
        return ;
    }

    // navigate the linked list
    int i = 1;
    printf("this linked list is:\n");
    for ( Node * pNode = head ; pNode != NULL ; pNode = pNode->next )
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
 * function return: none
 */
Node* insertNodeByValue( Node *head, int insertValue )
{
    // create a new node for this linked list
    Node *newNode = (Node *)malloc( sizeof(Node) );
    newNode->value = insertValue;
    newNode->next = NULL;

    Node *pPrevious = NULL, *pCurrent = head;
    // try to find the position in the linked list for deleteValue
    for ( ;
          pCurrent != NULL && pCurrent->value < insertValue;
          pPrevious = pCurrent, pCurrent = pCurrent->next )
    {
        ;
    }
    
    if ( pCurrent == NULL && pPrevious == NULL)
    {
        // it is an empty list
        head = newNode;
    }
    else if ( pCurrent == NULL && pPrevious != NULL )
    {
        // it is the end of the list
        pPrevious->next = newNode;
    }
    else if ( pCurrent != NULL && pPrevious == NULL )
    {
        // the new node is the first node
        newNode->next = head;
        head = newNode;
    }
    else
    {
        // the new node is in rest of the list
        pPrevious->next = newNode;
        newNode->next = pCurrent;
    }

    return head;
}


/*
 * function name: deleteNodeByValue
 * function arugment:
 *    Node* head, the head pointer;
 *    int delValue, the delete value;
 * function return: none
 */
Node* deleteNodeByValue( Node *head, int deleteValue )
{
    Node *pPrevious = NULL, *pCurrent = head;
    // try to find the position in the linked list for deleteValue
    for ( ;
          pCurrent != NULL && pCurrent->value != deleteValue;
          pPrevious = pCurrent, pCurrent = pCurrent->next )
    {
        ;
    }
    
    if ( pCurrent == NULL )
    {
        // it is an empty list, or, the node is not found
        printf("the input value is not found. \n");
        return head;
    }
    if ( pPrevious == NULL )
    {
        // the node is the first node
        head = pCurrent->next;
    }
    else
    {
        // the node is in rest of the list
        pPrevious->next = pCurrent->next;
    }
    printf("the input value is found and deleted. \n");
    free(pCurrent);
    
    return head;
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
    if ( head == NULL )
    {
        return;
    }

    Node *pCurrent = head, *pPrevious = NULL;
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
 * function name: deleteMultiNodeByValue
 * function arugment:
 *    Node* head, the head pointer;
 *    int delValue, the delete value;
 * function return: new head
 */
Node* deleteMultiNodeByValue( Node *head, int delValue )
{
    // if the linked list is empty
    if ( head == NULL )
    {
        printf("This linked list is empty. \n");
        return NULL;
    }

    // if the head matches the delete value
    int isFound = 0;
    Node *pTemp = NULL;
    while ( head->value == delValue )
    {
        pTemp = head;
        head = head->next;
        free( pTemp );
        isFound ++;

        if ( head == NULL )
        {
            printf("Total %d node is/are deleted.\n", isFound );
            return NULL;
        }
    } // end of while loop

    // else, at least one un-matched node is in the linked list
    // if only one node in this list, no need to compare
    if ( head->next == NULL )
    {
        return head;
    }

    // otherwise, compare the rest nodes
    Node *pPrevious, *pCurrent;
    for ( pPrevious = head, pCurrent = head->next;
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
    return head;
}


/*
 * function name: reverseLinkedList
 * function arugment:
 *    Node* head, the head pointer;
 * function return: new head
 */
Node* reverseLinkedList( Node *head )
{
    // no need to reverse
    if ( head == NULL || head->next == NULL )
    {
        return head;
    }

    Node *pPrevious, *pCurrent, *pNext;
    for ( pPrevious = head, pCurrent = head->next ;
          pCurrent != NULL;
        )
    {
        // store the next node
        pNext = pCurrent->next;
        // reverse the direction of pCurrent
        pCurrent->next = pPrevious;

        // move the two pointers to next
        pPrevious = pCurrent;
        pCurrent = pNext;
    }

    // the old head becomes the new tail of the list
    head->next = NULL;
    // return the old tail as the new head
    head = pPrevious;

    return head;
}
