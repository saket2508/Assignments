#include<stdio.h>
#include<stdlib.h>
void print(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void swap(int*a, int*b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void sort(int arr[], int n)
{
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j])
                swap(&arr[i],&arr[j]);
        }
    }

}
void rsort(int arr[], int n)
{
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]<arr[j])
                swap(&arr[i],&arr[j]);
        }
    }

}
int main(){
    int arr[100000];
    char c;
    int i=0;
    do{
        scanf("%d",&arr[i]);
        i++;
        scanf("%c",&c);

    }
    while(c!='\n');
    sort(arr,i);
    printf("Array in ascending order:- \t");
    print(arr,i);
    rsort(arr,i);
    printf("Array in descending order:- \t");
    print(arr,i);

    return 0;
}