#include<iostream>

long long int DP[31][31];

long long int C(int n,int k){
    if(k==0 || n==k)
        return 1;
    if(DP[n][k]!=0)
        return DP[n][k];
    return C(n-1,k-1) + C(n-1,k);
}

int main(){
    int a,b;
    std::cin>> a >> b;
    std::cout << C(a-1,b-1)<<std::endl;
}
