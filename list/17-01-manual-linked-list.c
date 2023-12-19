#include <stdio.h>
#include <stdlib.h>

// create a new struct
typedef struct node
{
    int value;
    struct node * next;
} Node;

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
    n1->next = n2;
    n2->value = 20;
    n2->next = n3;
    n3->value = 30;
    n3->next = NULL;
    // navigate this linked list
    printf("this linked list is:\n");
    printf("[%p] %04d %p\n", n1, n1->value, n1->next);
    printf("[%p] %04d %p\n", n2, n2->value, n2->next);
    printf("[%p] %04d %p\n", n3, n3->value, n3->next);
    printf("\n");
    // destroy this linked list
    free(n1);
    free(n2);
    free(n3);
    return 0;
}
