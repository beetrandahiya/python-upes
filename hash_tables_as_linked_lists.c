#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//hash tables as array of linked list

struct node{
    int data;
    int key;
    struct node *next;
};

int N;
int N=10;
struct node *array[10];

int hash_function(int key){
    return key%N;
}

void insert(int key,int value){

    int index=hash_function(key);
    
    struct node *item;
    item=malloc(sizeof(struct node));
    item->data=value;
    item->next=0;
    array[index]=item;
    //insert linked list to array
    printf("%d\n",array[index]->data);
  /*  if(array[index]->data==0){
        array[index]=item;
    }
    else{
        struct node *a;
        a=array[index];
        while(a->next!=NULL){
            a=a->next;
        }
        a->next=item;
    }
    */
    


}


int main(){

  /*  struct node *head;
    //allocate memory for node
    head = malloc(sizeof(struct node));

    head -> data=5;

    struct node *sec=NULL;
    */

    insert(3,34);
    insert(3,55);
    insert(3,65);
    
   // printf("%d",array[3]->next->data);

};

