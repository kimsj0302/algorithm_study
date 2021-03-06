#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 3010
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
	int T;
	cin >> T;
	while (T--) {
		for (int i = 0; i < MAX; i++) {
			graph[i].clear();
			level[i] = 0;
			for (int j = 0; j < MAX; j++) {
				c[i][j] = 0;
				f[i][j] = 0;
			}

		}
		int n, m;
		cin >> n >> m;
		S = 0;
		E = n + m + 1;
		for (int i = 1; i <= m; i++) {
			int a, b;
			cin >> a >> b;
			for (int j = a; j <= b; j++) {
				c[i][m + j] = 1;
				graph[i].push_back(m + j);
				graph[m + j].push_back(i);
			}
		}

		for (int i = 1; i <= m; i++) {

			c[S][i] = 1;
			graph[S].push_back(i);
			graph[i].push_back(S);
		}
		for (int i = 1; i <= n; i++) {

			c[m + i][E] = 1;
			graph[m + i].push_back(E);
			graph[E].push_back(m + i);
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
}
