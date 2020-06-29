#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dp[40010][210];
int dist[40010];
int visited[40010];
int depth[40010];
vector < vector<pair<int,int>> > graph;
void maketree(int here, int parent) {
	depth[here] = depth[parent] + 1;
	dp[here][0] = parent;
	for (int i = 1; i < 210; i++) {
		int tmp = dp[here][i - 1];
		dp[here][i] = dp[tmp][i - 1];
	}
	for (int i = 0; i < graph[here].size(); i++) {
		if (graph[here][i].first != parent) {
			maketree(graph[here][i].first, here);
		}
	}
}

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) graph.push_back(vector<pair<int, int>>());
	for (int i = 0; i < n-1; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back(make_pair(b,c));
		graph[b].push_back(make_pair(a, c));
		visited[a] = false;
		visited[b] = false;
	}
	queue<int> que;
	que.push(1);
	dist[1] = 0;
	visited[1] = true;
	while (!que.empty()) {
		int t = que.front();
		que.pop();
		for (int i = 0; i < graph[t].size(); i++) {
			if (!visited[graph[t][i].first]) {
				que.push(graph[t][i].first);
				dist[graph[t][i].first] = dist[t] + graph[t][i].second;
				visited[graph[t][i].first] = true;

			}
		}
	}
	depth[0]=-1;
	maketree(1, 0);
	scanf("%d", &m);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		int fa = a, fb = b;
		if (depth[a] < depth[b]) {
			int tmp;
			tmp = a;
			a = b;
			b = tmp;
		}
		for (int i = 209; i >= 0; i--) {
			if (depth[b] <= depth[dp[a][i]]) {
				a = dp[a][i];
			}
		}
		int lca = b;
		if (a != b) {
			for (int i = 209; i >= 0; i--) {
				if (dp[a][i] != dp[b][i]) {
					a = dp[a][i];
					b = dp[b][i];
				}
				lca = dp[b][i];
			}
		}
		printf("%d\n", dist[fa]+ dist[fb]- 2 * dist[lca]);
	}

}