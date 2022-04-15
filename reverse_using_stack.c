#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10


struct stack{
    char data[MAX];    // array of 10 integers
    int top;          // top pointer
};

typedef struct stack st;   //give a new name to the datatype

void createEmptyStack(st *s){
    s->top=-1;
}
//add an element to the stack
void push(st *s,char x){
    if(s->top==MAX-1){
        printf("Stack is full\n");
    }
    else{
        s->top++;
        s->data[s->top]=x;
    }
}

//remove an element from the stack
char pop(st *s){
    if(s->top==-1){
        printf("Stack is empty\n");
    }
    else{
        s->top--;
    }
    return s->data[s->top+1];
}

//display the stack
void display(st *s){
    if(s->top==-1){
        printf("Stack is empty\n");
    }
    else{
        int i;
        for(i=s->top;i>=0;i--){
            printf("%c",s->data[i]);
        }
    }
}

//reverse the stack using stack

st *reverse(st *s){
    st *temp = (st*)malloc(sizeof(st));
    createEmptyStack(temp);
    while(s->top!=-1){
        push(temp,pop(s));
    }
    return temp;
}


void main(){
    st *s=(st*)malloc(sizeof(st));
    createEmptyStack(s);
    push(s,'t');
    push(s,'i');
    push(s,'s');
    push(s,'h');
    push(s,'a');

    display(s);
    printf("\n-----------------\n");
    st *temp = reverse(s);

    printf("Reversed stack is:\n");
    printf("-----------------\n");

    display(temp);

}
