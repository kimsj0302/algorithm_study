#include<iostream>
#include<string>
using namespace std;
int arr[26]={3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
int main(){
    string a;
    cin >>a;
    int sum=0;
    for(int i=0;i<a.size();i++){
        sum+=arr[a[i]-'A'];
    }
    cout <<sum<<endl;
}
