//Linked List Implementation

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node;

int main(){
    node *first ;
    node *second ;
    node *third ;

    first = (node*)malloc(sizeof(node));
    second = (node*)malloc(sizeof(node));
    third = (node*)malloc(sizeof(node));

    first->data = 1;
    first->next = second;
    
    second->data = 2;

    printf("%d\n",first->next->data);
}