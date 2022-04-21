#include<stdio.h>

#include<stdlib.h>


// linear search

void linear_search(int arr[],int num){
    int size=sizeof(arr)/sizeof(arr[0]);
    int i;
    for(i=0;i<size;i++){
        if(arr[i]==num){
            printf("found");
            break;
        }
    };
    if(i==size){
        printf("not found");
    };
}

//binary search

void bubble_sort(int arr[],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void binary_search(int arr[],int num){
    int size=sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,size);
    int low=0;
    int high=size-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==num){
            printf("found");
            break;
        }
        else if(arr[mid]<num){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(low>high){
        printf("not found");
    }
}



int main() {
    int n;
    printf("Enter the size of array:\n");
    scanf("%d", & n);
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    bubble_sort(a, n);
    printf("Which number to check:\n");
    int num;
    scanf("%d", & num);
    binary_search(a, num);
    
    return 0;
}
