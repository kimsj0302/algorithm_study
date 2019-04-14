#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int sum=0;
    int st=-1;
    int nd=-1;
    int a,b;
    vector< pair<int,int> > arr;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        if(a<b)
            arr.push_back(make_pair(b,a));
        else
            arr.push_back(make_pair(a,b));
    }
    sort(arr.begin(),arr.end());
    for(int i=n-1;i>=0;i--){
        if(nd == -1){
            st=arr[i].second;
            nd=arr[i].first;
        }
        else{
            if(st<=arr[i].first){
                if(st>arr[i].second)
                    st = arr[i].second;
            }
            else{
                sum += nd - st;
                st=arr[i].second;
                nd=arr[i].first;
            }
        }
    }
    sum += nd-st;
    cout << sum << endl;
}
