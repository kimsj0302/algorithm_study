#include<iostream>
#include<algorithm>
using namespace std;

long long int gcd(long long int a,long long int b){
    long long int c;
    while(b!=0){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main(){
    long long int arr[5];
    for(int i=0;i<5;i++) cin >>arr[i];
    long long int m = 100000000000;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            long long int t=arr[i]*arr[j]/gcd(arr[i],arr[j]);
            for(int k=j+1;k<5;k++){
                m=min(m,t*arr[k]/gcd(t,arr[k]));
            }
        }
    }
    cout << m <<endl;
}
