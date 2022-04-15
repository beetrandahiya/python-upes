#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10


struct stack{
    int data[MAX];    // array of 10 integers
    int top;          // top pointer
};

typedef struct stack st;   //give a new name to the datatype

void createEmptyStack(st *s){
    s->top=-1;
}

// check if stack is empty

bool isEmpty(st *s){
    if(s->top==-1)
        return true;
    else
        return false;
}

//check if stack is full

bool isFull(st *s){
    if(s->top==MAX-1)
        return true;
    else
        return false;
}

// Add an element to the stack
void push(st *s,int x){
    if(isFull(s)){
        printf("Stack is full\n");
    }
    else{
        s->top++;
        s->data[s->top]=x;
    }
}

// Remove an element from the stack
void pop(st *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }
    else{
        s->top--;
    }
}

// Display the stack
void display(st *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }
    else{
        for(int i=0;i<=s->top;i++){
            printf("%d\n",s->data[i]);
        }
    }
}







int main(){
    st *s=(st *)malloc(sizeof(st));
    createEmptyStack(s);
    while(true){
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:
                int x;
                printf("Enter the element to be pushed\n");
                scanf("%d",&x);
                push(s,x);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                display(s);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}