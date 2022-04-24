#include<stdio.h>
#include<stdlib.h>
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
    printf("%d ", head->data);
    printList(head->next);
}

int hash(int key, int size){
    return key % size;
}

node *hashTable[10];

void insert(int key, int data){
    int index = hash(key, 10);
    makeList(&hashTable[index], data);
}

void printHashTable(){
    for(int i = 0; i < 10; i++){
        printf("%d: ", i);
        printList(hashTable[i]);
        printf("\n");
    }
}

//function to search for a key in the hashtable

void search(int key){
    int index = hash(key, 10);
    node* temp = hashTable[index];
    while(temp != NULL){
        if(temp->data == key){
            printf("%d found\n", key);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found\n", key);
}


void main(){
    insert(1, 1);
    insert(2, 2);
    insert(3, 3);
    insert(4, 4);
    insert(5, 5);
    insert(6, 6);
    insert(7, 7);
    insert(8, 8);
    insert(9, 9);
    insert(10, 10);
    insert(13, 13);
    insert(14, 14);
    insert(15, 15);
    insert(16, 16);
    insert(17, 17);
    printHashTable();
    printf("----------------------");
    search(13);
}

