#include<iostream>

using namespace std;


bool cal(int a,int b,int c){
    if(a<0 || b<0 || c<0) return false;
    if(a%15==0 && b%28==0 && c%19==0)return true;
    return false;
}

int main(){
    int E,S,M;
    cin >> E>>S>>M;
    int k=1;
    while(!cal(k-E,k-S,k-M)){
        k++;
    }
    cout << k <<endl;
}
