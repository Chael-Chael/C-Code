
#include <stdio.h>
#include <stdlib.h>

// structure of the node
typedef struct node
{
    int value;
    struct node * next;
} Node;

// function to create the linked list with input numNode
// function return: the pointer to head node
Node* createLinkedList( int numNode );

// function to insert a new node, linked list sorted by node value
// function return: the pointer to head node
Node* insertNodeByValue( Node *head , int insertValue );

// function to find and delete a node by value, multiple node version
// function return: the pointer to head node
Node* deleteNodeByValue( Node *head , int deleteValue );

// function to reverse the linked list
// function return: none
Node* reverseLinkedList( Node *head );

// function to sort the linked list
// function return: none
Node* sortLinkedList( Node *head );

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
    Node * listHead;
    // create a five node linked list for further program
    listHead = createLinkedList( 5 );
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
                listHead = insertNodeByValue( listHead, input );
                break;

            case 2:
                printf("Please input the value to delete: ");
                scanf("%d", &input );
                listHead = deleteNodeByValue( listHead, input ) ;
                break;

            case 3:
                listHead = reverseLinkedList( listHead ) ;
                break;

            case 4:
                listHead = sortLinkedList( listHead ) ;
                break;

            case 5:
                printf("Thank you for using this program. \n\n");
                continue;

            default:
                printf("Wrong input!\n\n");
                break;
        } // end of switch case

        displayLinkedList( listHead );

    } while ( choice != 5 );

    // destroy the linked list
    destroyLinkedList( listHead );

    return 0;
}


/*
 * function name: createLinkedList
 * function arugment:
 *          int numNode, the number of nodes
 * function return: Node* head, the head pointer
 */
Node* createLinkedList( int numNode )
{
    // if the linked list is empty
    if ( numNode < 1 )
    {
        return NULL;
    }

    // create the head node of linked list
    Node *head;
    head = malloc( sizeof(Node) );
    head->value = 10;
    head->next = NULL;

    int i;
    Node *pPrevious = head, *pCurrent = NULL;
    for ( i = 1 ; i < numNode; i ++ )
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
    for ( Node *pNode = head ; pNode != NULL ; pNode = pNode->next )
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
Node* insertNodeByValue( Node *head, int insertValue )
{
    // create a new node for this linked list
    Node *newNode = (Node *)malloc( sizeof(Node) );
    newNode->value = insertValue;
    newNode->next = NULL;

    if ( head == NULL )
    {
        // if the linked list is empty
        head = newNode;
        return head;
    }
    
    if ( insertValue < head->value )
    {
        // insert before the head
        newNode-> next = head;
        head = newNode;
        return head;
    }

    int isFound = 0;
    Node *previous, *current;

    // insert within the linked list
    for ( previous = NULL, current = head ;
          current != NULL ;
          previous = current, current = current->next )
    {
        // to find the position to insert
        if ( insertValue < current->value )
        {
            // insert the node between the two
            previous->next = newNode;
            newNode->next = current;
            isFound = 1;
            break;
        }
    }
    if ( !isFound )
    {
        // insert into the last node
        previous->next = newNode;
    }
    return head;
}


/*
 * function name: deleteNodeByValue( Multiple Node version)
 * function arugment:
 *    Node* head, the head pointer;
 *    int delValue, the delete value;
 * function return: new head
 */
Node* deleteNodeByValue( Node *head, int deleteValue )
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
    while ( head->value == deleteValue )
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
        if ( pCurrent->value == deleteValue )
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
 * function name: reverseLinkedList
 * function arugment:
 *    Node* head, the head pointer;
 * function return: Node* head
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


/*
 * function name: sortLinkedList
 * function arugment:
 *    Node* head, the head pointer;
 * function return: Node* head
 */
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

    Node *pPrevious = NULL;
    Node *pCurrent = NULL;
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
