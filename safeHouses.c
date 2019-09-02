#include<stdio.h>
#include<stdlib.h>
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
int safeHouses(int*arr, int n, int x, int y){
    int range = x*y;
    sort(arr,n);
    int count= 0;
    int sum = 0;
    int*safe = (int*)malloc(sizeof(int)*2*n);
    int j=0;
    for(int i=0,j=0;i<2*n,j<n;i+=2,j++){
        *(safe+i) = *(arr+j) - range;
        *(safe+i+1) = *(arr+j) + range;
        
    }
    for(int i=1;i<2*n-1;i+=2){
        if(*(safe+i) < *(safe+i+1))
            count = *(safe+i+1)-*(safe+i)-1;
            sum+= count;

    }

    if(*(safe)< 0){
        count = 0;
    }

    else{
        count = *(safe)-1;
    }

    sum = sum + count;

    if(*(safe + 2*n -1) > 150){
        count = 0;
    }

    else{
        count = 150 - *(safe+ 2*n - 1);
    }
    
    sum = sum + count;

    free(safe);

    return sum;

    

}
int main(){
    int T, M, x, y;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&M);
        scanf("%d",&x);
        scanf("%d",&y);
        int*cops = (int*)malloc(sizeof(int)*M);
        for(int j=0;j<M;j++){
            scanf("%d",cops+j);
        }
        int res = safeHouses(cops,M,x,y);
        printf("%d",res);
        free(cops);
    }

    return 0;
}
    
