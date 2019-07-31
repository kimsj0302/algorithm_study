#include<iostream>
#include<string>
using namespace std;

int main(){
        string a;
        cin >> a;
        int sum=0;
        for(int i=0;i<a;i++){
            if(a[i]=' ') sum++;
        }
        cout <<sum<<"\n";
}
