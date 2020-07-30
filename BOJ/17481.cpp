#include<iostream>
#include<map>
#include<vector>
using namespace std;
bool c[2001];
int d[2001];
vector<int> arr[2001];

bool dfs(int x){
    for(int i=0;i<arr[x].size();i++){
        int now = arr[x][i];
        if(c[now]) continue;
        c[now]=true;

        if(d[now]==0||dfs(d[now])){
            d[now]=x;
            return true;
        }
    }
    return false;
}

int main(){
    map<string,int> toint;
    int n,m;
    cin >>n >> m;
    for(int i=0;i<m;i++){
        string tmp;
        cin >> tmp;
        toint[tmp]=i;
    }
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        while(k--){
            string t;
            cin >> t;
            arr[i+m].push_back(toint[t]);
        }
    }
    int count =0;
    for(int i=n;i<n+m;i++){
        fill(c,c+2001,false);
        if(dfs(i)) count ++;
    }
    if(count == n){
        cout << "YES\n";
    }
    else{
        cout <<"NO\n"<<count;
    }

}