#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node * next;
} Node;

// function to display the linked list with pointer to head
// function return: none
void displayLinkedList( Node *head );

int main()
{
    // declare the pointers to different nodes
    Node *n1, *n2, *n3;
    // create the nodes
    n1 = (Node *)malloc( sizeof(Node) );
    n2 = (Node *)malloc( sizeof(Node) );
    n3 = (Node *)malloc( sizeof(Node) );
    
    // create the linked list by pointer assignment
    n1->value = 10;
    n1->next = n3;
    n3->value = 20;
    n3->next = n2;
    n2->value = 30;
    n2->next = NULL;
    
    // navigate and display this linked list
    displayLinkedList( n1 );
    
    // destroy this linked list
    free(n1);
    free(n2);
    free(n3);
    return 0;
}

void displayLinkedList( Node *head )
{
    printf("this linked list is:\n");
    for (Node *pNode = head ; pNode != NULL ; pNode = pNode->next )
    {
        printf("[%p] %04d %p\n", pNode, pNode->value, pNode->next);
    }
    printf("\n");
}



