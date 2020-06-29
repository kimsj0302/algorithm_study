#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dp[100010][400];
int depth[100010];
vector < vector<int> > graph;
void maketree(int here, int parent) {
	depth[here] = depth[parent] + 1;
	dp[here][0] = parent;
	for (int i = 1; i < 400; i++) {
		int tmp = dp[here][i - 1];
		dp[here][i] = dp[tmp][i - 1];
	}
	for (int i = 0; i < graph[here].size(); i++) {
		if (graph[here][i] != parent) {
			maketree(graph[here][i], here);
		}
	}
}

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) graph.push_back(vector<int>());
	for (int i = 0; i < n-1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	queue<int> que;
	que.push(1);
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
		for (int i = 400-1; i >= 0; i--) {
			if (depth[b] <= depth[dp[a][i]]) {
				a = dp[a][i];
			}
		}
		int lca = b;
		if (a != b) {
			for (int i = 400 - 1; i >= 0; i--) {
				if (dp[a][i] != dp[b][i]) {
					a = dp[a][i];
					b = dp[b][i];
				}
				lca = dp[b][i];
			}
		}
		printf("%d\n", lca);
	}

}