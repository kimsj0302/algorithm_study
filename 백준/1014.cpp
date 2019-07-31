#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 2010
using namespace std;

int level[MAX];
vector<int> graph[MAX];
int c[MAX][MAX], f[MAX][MAX];
int work[MAX];
int S, E;

int arr[101][101];

bool bfs() {
	for (int i = 0; i < MAX; i++) level[i] = -1;
	level[S] = 0;
	queue<int> que;
	que.push(S);
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			if (level[next] == -1 && c[now][next] - f[now][next] > 0) {
				level[next] = level[now] + 1;
				que.push(next);
			}
		}
	}
	return level[E] != -1;
}

int dfs(int now, int dest, int flow) {
	if (now == dest) return flow;
	for (int& i = work[now]; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (level[next] == level[now] + 1 && c[now][next] - f[now][next] > 0) {
			int re = dfs(next, dest, min(c[now][next] - f[now][next], flow));
			if (re > 0) {
				f[now][next] += re;
				f[next][now] -= re;
				return re;
			}
		}
	}
	return 0;
}

void connect(int src,int dest,int cap,bool bi){
	c[src][dest]=cap;
	if(bi) c[dest][src]=cap;
	graph[src].push_back(dest);
	graph[dest].push_back(src);
	//cout << "connect "<<src<<"TO "<<dest<<endl;
}

int num(int x,int y,int m){
	return m*x+y+1;
}

int main() {
	int T;
	cin >>T;
	while(T--){
		for (int i = 0; i < MAX; i++) {
			graph[i].clear();
			level[i] = 0;
			for (int j = 0; j < MAX; j++) {
				c[i][j] = 0;
				f[i][j] = 0;
			}

		}
		int n,m;
		cin >>n>>m;
		int sum=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				char a;
				cin >>a;
				if(a=='.'){
					arr[i][j]=1;
					sum++;
				}
				else{
					arr[i][j]=0;
				}
			}
		}
		S=0;
		E=n*m+1;
		for(int j=0;j<m;j+=2){
			for(int i=0;i<n;i++){
				if(arr[i][j]==0)
					continue;
				connect(S,num(i,j,m),1,false);
				if(j!=0){
					if(arr[i][j-1]){
						connect(num(i,j,m),num(i,j-1,m),1,false);
					}
					if(i!=n-1 && arr[i+1][j-1]){
						connect(num(i,j,m),num(i+1,j-1,m),1,false);
					}
					if(i!=0 && arr[i-1][j-1]){
						connect(num(i,j,m),num(i-1,j-1,m),1,false);
					}
				}
				if(j!=m-1){
					if(arr[i][j+1]){
						connect(num(i,j,m),num(i,j+1,m),1,false);
					}
					if(i!=0 && arr[i-1][j+1]){
						connect(num(i,j,m),num(i-1,j+1,m),1,false);
					}
					if(i!=n-1 && arr[i+1][j+1]){
						connect(num(i,j,m),num(i+1,j+1,m),1,false);
					}
				}
			}
		}
		for(int j=1;j<m;j+=2){
			for(int i=0;i<n;i++){
				if(!arr[i][j])
					continue;
				connect(num(i,j,m),E,1,false);
			}
		}
		int answer = 0;
		while (bfs()) {
			for (int i = 0; i < MAX; i++) work[i] = 0;
			while (1) {
				int flow = dfs(S,E, 100000);
				if (flow == 0) break;
				answer += flow;
			}
		}
		cout <<sum-answer<<endl;
	}
}
