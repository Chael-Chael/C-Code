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


int main(void)
{
    Node * listHead = createLinkedList( 3 );
    displayLinkedList( listHead );

    int choice = 0, input = 0;
    do
    {
        printf("Please input your choice (1=insert, 2=delete, 3=exit): ");
        scanf("%d", &choice );

        switch ( choice )
        {
            case 1:
                printf("Please input the insert value: ");
                scanf("%d", &input );
                listHead = insertNodeByValue( listHead, input );
                displayLinkedList( listHead );
                break;

            case 2:
                printf("Please input the value to delete: ");
                scanf("%d", &input );
                listHead = deleteNodeByValue( listHead, input ) ;
                displayLinkedList( listHead );
                break;

            case 3:
                printf("Thank you for using this program. \n");
                break;

            default:
                printf("Wrong input!\n\n");
                break;
        } // end of switch case

    } while ( choice!=3 );

    // destory the linked list
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
    printf("\nCurrent list: ");
    for ( Node *pNode = head; pNode != NULL; pNode = pNode->next )
    {
         printf(" %2d -->", pNode->value );
    }
    printf("\b\b\b\b       \n");
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
