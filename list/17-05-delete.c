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

// function to insert a new node, linked list sorted by node value
// function return: the pointer to head node
Node* insertNodeByValue( Node *head , int insertValue );

// function to find and delete a node by value
// function return: the pointer to head node
Node* deleteNodeByValue( Node *head , int deleteValue );

int main()
{
    Node *listHead = createLinkedList( 3 );
    displayLinkedList( listHead );

    int deleteValue;
    printf("Please input the value to delete: \n");
    scanf("%d", &deleteValue );

    listHead = deleteNodeByValue( listHead, deleteValue );
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
 * function name: deleteNodeByValue
 * function arugment:
 *    Node* head, the head pointer;
 *    int delValue, the delete value;
 * function return: none
 */
Node* deleteNodeByValue( Node *head, int deleteValue )
{
    if ( head == NULL )
    {
        // if the linked list is empty
        printf("the linked list is empty \n");
        return NULL;
    }

    Node *temp;
    if ( deleteValue == head->value )
    {
        // to delete the head
        temp = head;
        head = head->next ;
        free(temp);
        printf("the input value is found and deleted. \n");
        return head;
    }

    int isFound = 0;
    Node *previous, *current;
    for ( previous = NULL, current = head ;
          current != NULL ;
          previous = current, current = current->next )
    {
        if ( deleteValue == current->value )
        {
            // delete the node, free the memory
            previous->next = current->next;
            free(current);
            isFound = 1;
            break;
        }
    }
    if ( isFound )
    {
        printf("the input value is found and deleted. \n");
    }
    else
    {
        printf("the input value is not found. \n");
    }

    return head;
}
