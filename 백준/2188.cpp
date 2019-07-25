#include<iostream>
#include<vector>
#define MAX 230
using namespace std;

int visited[MAX];
vector<int> node[MAX];
int b[MAX];
int dfs(int here){
    if(visited[here]) return 0;
    visited[here]=1;
    for(int i=0;i<node[here].size();i++){
        int there=node[here][i];
        if(!b[there]||dfs(b[there])){
            b[there]=here;
            return 1;
        }
    }
    return 0;
}

int match(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int k=0;k<MAX;k++)
            visited[k]=0;
        if(dfs(i))sum++;
    }
    return sum;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            int tmp;
            scanf("%d",&tmp);
            node[i].push_back(tmp);
        }
    }
    printf("%d\n",match(n));
}
