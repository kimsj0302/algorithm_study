#include<iostream>

int gcd(int a,int b){
    while(b!=0){
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main(){
    int n,m;
    char c;
    scanf("%d %1c %d",&n,&c,&m);
    printf("%d:%d",n/gcd(n,m),m/gcd(n,m));
}
