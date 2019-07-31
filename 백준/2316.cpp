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
	S = n+1;
	E = 2;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		c[n+a][b] = 1000000;
		c[n+b][a] = 1000000;
		graph[n+a].push_back(b);
		graph[b].push_back(n+a);
		graph[n+b].push_back(a);
		graph[a].push_back(n+b);
	}
	for(int i=1;i<=n;i++){
		c[i][i+n]=1;
		graph[i].push_back(i+n);
		graph[i+n].push_back(i);
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
