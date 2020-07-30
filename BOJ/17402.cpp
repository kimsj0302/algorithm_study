#include<iostream>
#include<vector>
using namespace std;
vector<int> arr[401];
bool c[401];
int d[401];
bool dfs(int x){
    for(int i=0;i<arr[x].size();i++){
        int n = arr[x][i];
        if(c[n]) continue;
        c[n]=true;
        if(d[n]==0||dfs(d[n])){
            d[n]=x;
            return true;
        }
    }
    return false;
}
int main(){
    int n,m,x;
    cin >>n>>m>>x;
    while(x--){
        int a,b;
        cin >>a>>b;
        arr[a].push_back(b+n);
    }
    int count =0;
    for(int i=1;i<=n;i++){
        fill(c,c+401,false);
        if(dfs(i)) count ++;
    }
    cout << n+m-count<<"\n";
}