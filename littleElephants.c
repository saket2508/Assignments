#include<stdio.h>
#include<stdlib.h>
void isHappy(int*arr, int c, int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum + *(arr+i) + 2;
    }
    if(sum <= c)
        printf("YES");
    else
        printf("NO");
    

}
int main(){
    int T;
    int n, c;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&n);
        scanf("%d",&c);
        int*arr = (int*)malloc(sizeof(int)*n);
        for(int j=0;j<n;j++){
            scanf("%d",arr+j);
        }
        isHappy(arr,c,n);

    }
    return 0;
}