#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[51];
int main(){
    int n;
    cin >>n;
    vector<int> c;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        c.push_back(tmp);
    }
    int m;
    cin >> m;
    vector<int> b;
    for(int i=0;i<m;i++){
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
    }
    sort(c.begin(),c.end());
    sort(b.begin(),b.end());
    if(c[n-1]<b[m-1]){
        cout <<"-1\n";
        return 0;
    }
    int now=0;
    int i;
    for(i=0;i<m;i++){
        if(b[i]<=c[now]){
            arr[now]++;
        }
        else{
            now++;
            i--;
        }
    }
    for(int i=n-2;i>=0;i--){
        arr[i]+=arr[i+1];
    }
    int res=0;
    for(int i=0;i<n;i++){
        if(arr[i]%(n-i)==0)
            res=max(res,arr[i]/(n-i));
        else
            res=max(res,arr[i]/(n-i)+1);
    }
    cout << res << endl;

}
