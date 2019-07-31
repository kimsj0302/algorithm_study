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
	que.push(0);
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
				//cout << "flow " << now <<" to " << next << ":" << re<<endl;
				return re;
			}
		}
	}
	return 0;
}


int main() {
	int n, m,k;
	scanf("%d %d %d", &n, &m,&k);
	S = 0;
	E = n + m + 1;
	c[S][E + 1] = k;
	graph[S].push_back(E + 1);
	graph[E + 1].push_back(S);
	for (int i = 1; i <= n; i++) {
		int job;
		scanf("%d", &job);
		for (int j = 0; j < job; j++) {
			int tmp;
			scanf("%d", &tmp);
			c[i][n + tmp] = 1;
			graph[i].push_back(n + tmp);
			graph[n + tmp].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		c[S][i] = 1;
		graph[S].push_back(i);
		graph[i].push_back(S);
		c[E+1][i] = k;
		graph[E + 1].push_back(i);
		graph[i].push_back(E + 1);

	}
	for (int i = 1; i <= m; i++) {
		c[n + i][E] = 1;
		graph[n + i].push_back(E);
		graph[E].push_back(n + i);
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
	printf("%d\n", ans);
}