#include <stdio.h>

int main(){


}

int hash_fn(char SAPID[]){
    int l=strlen(SAPID);
    int n=100*atoi(SAPID[0])+10*atoi(SAPID[1])+atoi(SAPID[2]);
    int a;
    a=sum_of_digits(num);
    while(a>10){
        a=sum_of_digits(a);
    }
    return a;
    
}

int sum_of_digits(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
