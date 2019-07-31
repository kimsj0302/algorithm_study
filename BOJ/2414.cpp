#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 2010
using namespace std;
int arr[MAX][MAX];
int row[MAX][MAX];
int col[MAX][MAX];

int level[MAX];
vector<int> graph[MAX];
int c[MAX][MAX], f[MAX][MAX];
int work[MAX];
int S, E;
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


int main() {
	int n, m;
	cin >> n >> m;
	S = 0;
	E = MAX-1;
	for(int i=0;i<n;i++){
		string tmp;
		cin >> tmp;
		for(int j=0;j<m;j++){
			arr[i][j]=(tmp[j]=='*'?1:0);
		}
	}
	int rnow=1;
	bool insert=false;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]){
				row[i][j]=rnow;
				insert=true;
			}
			else if(insert){
				rnow++;
				insert=false;
			}
		}
		rnow++;
	}
	for(int i=1;i<=rnow;i++){
		c[S][i]=1;
		graph[S].push_back(i);
		graph[i].push_back(S);
	}
	int cnow=rnow+1;
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			if(arr[i][j]){
				col[i][j]=cnow;
				insert=true;
			}
			else if(insert){
				cnow++;
				insert=false;
			}
		}
		cnow++;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << row[i][j]<<" ";
		}
		cout << "\n";
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << col[i][j]<<" ";
		}
		cout << "\n";
	}
	for(int i=rnow+1;i<=cnow;i++){
		c[i][E]=1;
		graph[E].push_back(i);
		graph[i].push_back(E);
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]){
				c[row[i][j]][col[i][j]]=1;
				graph[row[i][j]].push_back(col[i][j]);
				graph[col[i][j]].push_back(row[i][j]);
			}
		}
	}
	int ans = 0;
	while (bfs()) {
		for (int i = 0; i < MAX; i++) work[i] = 0;
		while (1) {
			int flow = dfs(S, E, 10000);
			if (!flow) break;
			ans += flow;
		}
	}
	cout << ans << endl;
}
