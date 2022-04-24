//Linked List Implementation

#include <stdio.h>
#include <stdlib.h>

//make linked lists

typedef struct node{
    int data;
    struct node* next;
}node;

void makeList(node** head, int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
    }else{
        node* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(node* head){
    if(head == NULL){
        return;
    }
    printf("|%d|--->", head->data);
    printList(head->next);
}

//recursive linear search
void search(node* head, int data){
    if(head == NULL){
        return;
    }
    if(head->data == data){
        printf("%d found\n", data);
        return;
    }
    search(head->next, data);
}

int main(){

    node* head = NULL;
    makeList(&head, 1);
    makeList(&head, 2);
    makeList(&head, 3);
    makeList(&head, 4);
    makeList(&head, 5);
    makeList(&head, 6);
    makeList(&head, 7);
    makeList(&head, 8);
    makeList(&head, 9);
    makeList(&head, 10);
    printList(head);
    printf("\n");
    search(head, 5);
    return 0;
}