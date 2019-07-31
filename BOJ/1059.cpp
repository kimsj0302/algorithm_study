#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    int l,r;
    l=0;
    r=1000;
    int k;
    cin >> k;
    for(int i=0;i<n;i++){
        if(arr[i]<=k)
            l=max(l,arr[i]);
        else
            r=min(r,arr[i]);
    }
    cout << max((k-l)*(r-k)-1,0)<<endl;
}
