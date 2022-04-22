#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

void makeTree(node** head, int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if(*head == NULL){
        *head = newNode;
    }else{
        node* temp = *head;
        while(temp->left != NULL){
            temp = temp->left;
        }
        temp->left = newNode;
    }
}

void insert(node** head, int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if(*head == NULL){
        *head = newNode;
    }else{
        node* temp = *head;
        if(data < temp->data){
            while(temp->left != NULL){
                temp = temp->left;
            }
            temp->left = newNode;
        }else{
            while(temp->right != NULL){
                temp = temp->right;
            }
            temp->right = newNode;
        }
    }
}

void printTree(node* head){
    if(head == NULL){
        return;
    }
    printf("%d ", head->data);
    printTree(head->left);
    printTree(head->right);
}


void main(){

    node* head = NULL;

    makeTree(&head, 10);
    insert(&head, 5);
    insert(&head, 15);
    insert(&head, 20);
    insert(&head, 1);

    printTree(head);
}