#include<iostream>

long long int gcd(long long int a, long long int b){
    while(b!=0){
        long long int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main(){
    long long int n,m;
    scanf("%lld %lld",&n,&m);
    long long int result=gcd(n,m);
    for(long long int i=0;i<result;i++){
        printf("1");
    }
}
