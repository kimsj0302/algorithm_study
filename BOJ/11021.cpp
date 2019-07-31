#include<iostream>

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("Case #%d: %d\n",i+1,a+b);
    }
}