#include<iostream>
#include<string>
using namespace std;

int main(){
    char arr[1000010];
    cin.getline(arr,1000010);
    int sum=1;
    int i;
    for(i=0;arr[i];i++){
        if(arr[i]==' ') sum++;
    }
    if(arr[i-1]==' ')sum--;
    if(arr[0]==' ')sum--;
    cout <<sum<<"\n";
}
