#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int level[100];
vector<int> graph[100];
int c[100][100],f[100][100];
int work[100];
bool bfs(){
    for(int i=0;i<100;i++) level[i]=-1;
    level[0]=0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int now=que.front();
        que.pop();
        for(int i=0;i<graph[now].size();i++){
            int next=graph[now][i];
            if(level[next]== -1 && c[now][next]-f[now][next]>0){
                level[next]=level[now]+1;
                que.push(next);
            }
        }
    }
    return level['Z'-'A'] != -1 ;
}

int dfs(int now,int dest,int flow){
    if(now==dest) return flow;
    for(int &i=work[now];i<graph[now].size();i++){
        int next=graph[now][i];
        if(level[next] == level[now]+1 && c[now][next]-f[now][next]>0){
            int re=dfs(next,dest,min(c[now][next]-f[now][next],flow));
            if(re>0){
                f[now][next]+=re;
                f[next][now]-=re;
                //cout << "flow " << now <<" to " << next << ":" << re<<endl;
                return re;
            }
        }
    }
    return 0;
}


int main(){
    int n;
    cin >> n;

    for(int test=0;test<n;test++){
        char a,b;
        int f;
        cin >>a>>b>>f;
        int ta,tb;
        if(a<91)
            ta=a-'A';
        else
            ta=a-'a'+'Z'-'A'+1;
        if(b<91)
            tb=b-'A';
        else
            tb=b-'a'+'Z'-'A'+1;
        c[ta][tb]+=f;
        c[tb][ta]+=f;
        graph[ta].push_back(tb);
        graph[tb].push_back(ta);
    }
    int total=0;
    while(bfs()){
        for(int i=0;i<100;i++) work[i]=0;
        while(1){
            int fl=dfs(0,'Z'-'A',10000000);
            if(fl==0)break;
            total+=fl;
        }
    }
    cout << total <<endl;
}