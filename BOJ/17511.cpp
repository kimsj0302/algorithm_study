#include<iostream>

using namespace std;
int arr[510];
int main(){
    int n;
    int m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >>a>>b;
        arr[b]=1;
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        if(arr[i]==0) sum++;
    }
    cout << sum <<endl;
    for(int i=1;i<=n;i++){
        if(arr[i]==0) cout << i << endl;
    }

}
