#include<stdio.h>
#include<stdlib.h>
void print(int*arr, int n){
    for(int i=0;i<n;i++){
        
       printf("%d\t",*(arr+i));
   } 
}
void swap(int*a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort(int*arr, int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(*(arr+i)>*(arr+j))
                swap(arr+i,arr+j);
        }
    }
}
int isEqual(int*arr, int n){
   //checks if all the elements of the array are equal or not
    for(int i=0;i<n-1;i++){
        //if the succeeding element is not equal to the preceeding element, return 0
        if(*(arr+i)!=*(arr+i+1))
            return 0;
    }
    //else, return 1
    return 1;
}
int minSteps(int*arr, int n){
    int count = 0;
    //the array is sorted
    sort(arr,n);
    //we create a variable that wil store the maximum salary of all the employees
    int maxSal = *(arr+n-1);
    //loop until the the salary of all the employees is not equal
    while(isEqual(arr,n)!= 1){
        while(*(arr+0)!= maxSal){
    //increment the salary of all the employees except the one with the highest salary until the salary of the first employee becomes equal to maxSal
            for(int i=0;i<n-1;i++){
                *(arr+i) = *(arr+i) + 1;
            }
            //at the end of each loop increment the counter var
            count++;
            

        }
        //sort the array
        sort(arr,n);
        //the maximum salary is stored
        maxSal =*(arr+n-1);
    
    }

    return count;
}

int main(){
    int T;
    //Denotes the no of test cases
    scanf("%d",&T);

    for(int i=0;i<T;i++){
        int n;
        //enter the no of employees
        scanf("%d",&n);
        //memory for an array containing the salary of n employees is allocated
        int*sal = (int*)malloc(sizeof(int)*n);
        for(int j=0;j<n;j++){
            *(sal+j) = 0;
        }
        for(int j=0;j<n;j++){
            scanf("%d",sal+j);
        }
        
        int res = minSteps(sal,n);
        //result is displayed
        printf("%d\n",res);
        //memory block is freed
        free(sal);

    }
    return 0;
}