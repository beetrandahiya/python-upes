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
        if(front<=rear){
            for(int i=front;i<=rear;i++){
                printf("%d ",items[i]);
            }
            printf("\n----------------\n");
        }
        else{
            for(int i=front;i<MAX;i++){
                printf("%d ",items[i]);
            }
            for(int i=0;i<=rear;i++){
                printf("%d ",items[i]);
            }
            printf("\n----------------\n");
        }
    }
}

void main(){
    while(true){
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element to be enqueued\n");
                int item;
                scanf("%d",&item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}
