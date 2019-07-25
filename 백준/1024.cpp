#include<iostream>
using namespace std;

int main(){
    int k,n;
    scanf("%d %d",&k,&n);
    while(n<=100){
        int u=n-n*n+2*k;
        int d=2*n;
        if(u%d==0) break;
        n++;
    }
    if(n>100){
        printf("-1\n");
    }
    else{
        int a = (n-n*n+2*k)/(2*n);
        if(a<0){
            printf("-1\n");
        }
        else{
            for(int i=0;i<n;i++){
                printf("%d ",a+i);
            }
        }
    }
}
