#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;

int dp[5001][5001];
vector<pair<int,int> > arr;

int n;
int cal(int i,int j){
    if(i==0 && j==1) return arr[0].second;
    if(dp[i][j]!=0) return dp[i][j];
    int tmp=INT_MAX;
    if(i>0 && i-1<=j){
        tmp=min(tmp,cal(i-1,j)+arr[i+j-1].first);
    }
    if(j>0 && i<=j-1){
        tmp=min(tmp,cal(i,j-1)+arr[i+j-1].second);
    }
    return dp[i][j]=tmp;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        arr.push_back(make_pair(a,b));
    }

    dp[1][0]=arr[0].first;
    dp[0][1]=arr[0].second;
    cout << cal(n/2,n/2) << endl;
}
