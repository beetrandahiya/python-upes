// Circular Queue Implementation

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5


int items[MAX];
int front = -1;
int rear = -1;
int count = 0;

void enqueue(int item){
    if(count==MAX){
        printf("Queue is full\n");
    }
    else{
        if(front==-1){
            front=0;
        }
        rear=(rear+1)%MAX;
        items[rear]=item;
        count++;
    }
}

void dequeue(){
    if(front==-1){
        printf("Queue is empty\n");
    }
    else{
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%MAX;
        }
    }
}

void display(){
    if(front==-1){
        printf("Queue is empty\n");
    }
    else{
       
    }
}
