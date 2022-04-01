#include <stdio.h>

int main(){
    

}

int hash_fn(char SAPID[]){
    int l=strlen(SAPID);
    int num=100*atoi(SAPID[l-3])+10*atoi(SAPID[l-2])+atoi(SAPID[l-1]);
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
