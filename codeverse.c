#include<stdio.h>

int sum_of_digits(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

void main(){
    n=scanf("%d",&n);
    for (i=0;i<n;i++){
        
        int a;
        a=sum_of_digits(995);
        while(a>10){
            a=sum_of_digits(a);
        }
        printf("%d\n",a);
    }
   
}