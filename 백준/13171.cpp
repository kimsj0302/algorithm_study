#include<iostream>
#define MOD 1000000007
using namespace std;

long long int mul(long long int n,long long int x){
    if(x==0)
        return 0;
    if(x==1)
        return n;
    long long int tmp;
    tmp=mul(n,x/2);
    if(x%2==0)
        return ((tmp%MOD)*(tmp%MOD))%MOD;
    else
        return ((((tmp%MOD)*(tmp%MOD))%MOD)*n)%MOD;
}

int main(){
    long long int n,x;
    scanf("%lld %lld",&n,&x);
    printf("%lld\n",mul(n%MOD,x));
}
