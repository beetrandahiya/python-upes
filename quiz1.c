#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int no;
    struct node *next;
}*head,*ptr;

typedef struct node node;

int main(){
    node *head ;
    node *second ;
    node *third ;
    node *fourth ;
    node *fifth ;
    node *sixth ;
    node *seventh ;

    head = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));
    fourth = (node *)malloc(sizeof(node));
    fifth = (node *)malloc(sizeof(node));
    sixth = (node *)malloc(sizeof(node));
    seventh = (node *)malloc(sizeof(node));


    head->no = 1;
    head->next = second;

    second->no = 2;
    second->next = third;

    third->no = 3;
    third->next = fourth;

    fourth->no = 4;
    fourth->next = fifth;

    fifth->no = 5;
    fifth->next = sixth;

    sixth->no = 6;
    sixth->next = seventh;

    seventh->no = 7;
    seventh->next = NULL;

   // shuffle(first);
//print(first);
    trythis();
    print(head);


}

void trythis(){
    struct node *x = (struct node *)malloc(sizeof(struct node));
    x->next = NULL;
    if(head==NULL){
        head = x;
    }
    else{
        for(ptr=head;ptr->next!=NULL;ptr=ptr->next);
        ptr->next = x;
    }
}

void print(struct node *head)
{
    struct node *p;
    p = head;
    while(p)
    {
        printf("%d ", p->no);
        p = p->next;
    }
    printf("\n");
}