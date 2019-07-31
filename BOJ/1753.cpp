#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main() {
	int V, E;
	scanf("%d %d", &V, &E);
	int st;
	scanf("%d", &st);
	vector<pair<int, int>> adj[20001];
	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
	}
	vector<int> P(V + 2, 1e9);
	priority_queue<pair<int,int>> q;
	
	P[st] = 0;
	q.push(make_pair(0, st));
	while (!q.empty()) {
		int val = -1 * q.top().first;
		int here = q.top().second;
		q.pop();
		if (P[here] > val) continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int rode = adj[here][i].second;
			if (P[there] > rode + val) {
				P[there] = rode + val;
				q.push(make_pair(-1 * (rode + val), there));
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (P[i] == 1e9)
			printf("INF\n");
		else
			printf("%d\n", P[i]);
	}
}