
#include <stdio.h>


int items[4];
int size=4;
int in=0;
int out=0;
int count=0;
int n=0;

void insert(int val){
    if(count<size){
    items[in]=val;
    in=(in+1)%size;
    count++;
    n++;
    }
    else{
        printf("queue is filled, come some other day! \n");
    }
}  
void delete(){
    if(count>0){
    items[out]=0;
    out=(out+1)%size;
    count--;
    n++;
        
    }
    else{
        printf("its as empty as your brain, go away! \n");

    }
}
void display(){
    if(in<out){
        if(n<size){
        for(int i=in;i<out;i++){
            printf("%d \n",items[i]);
        }}
        else{
            for(int i=0;i<size;i++){
            printf("%d \n",items[i]);
        }
        }
    }
    else if(in>out){
        if(n<size){
        for(int i=out;i<in;i++){
            printf("%d \n",items[i]);
        }}
        else{
            for(int i=0;i<size;i++){
            printf("%d \n",items[i]);
        }
        }
    }
    else if(in==out && count>=0){
        for(int i=0;i<size;i++){
            
                printf("%d \n",items[i]);
            
        }
    }
    else if(in==out && count==0){
        printf("empty");
    }
}
void printinfo(){
     printf("count = %d \n",count);
printf("out = %d \n",out);
printf("in = %d \n",in);
}

int main()
{
    int j=0;
   while(j<1){
       printf("----------------------------------\n");
       printf("Enter 1 for insert \n Enter 2 for delete \n Enter 3 for display");
       int option;
       scanf("%d",&option);
       switch(option){
           case 1:
               printf("Enter the number to insert \n");
               int val;
               scanf("%d",&val);
               insert(val);
               break;
           case 2:
               delete();
               break;
           case 3:
               display();
               break;
       }
       
   }
   
}






