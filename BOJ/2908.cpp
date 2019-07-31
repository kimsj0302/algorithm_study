#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n,m;
    cin >>n>>m;

    int a=n/100+(n%100/10)*10+(n%10)*100;
    int b=m/100+(m%100/10)*10+(m%10)*100;
    cout << max(a,b)<<endl;
}
