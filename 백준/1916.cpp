#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main() {
	int V, E;
	scanf("%d", &V);
	scanf("%d", &E);
	vector<pair<int, int> > adj[10002];
	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--;
		v--;
		adj[u].push_back(make_pair(v, w));
	}
	int st, nd;
	
	scanf("%d %d", &st, &nd);
	st--;
	nd--;
	priority_queue<pair<int, int> > q;
	vector<int> P(V + 1, 1e9);
	P[st] = 0;
	q.push(make_pair(0, st));

	while (!q.empty()) {
		int val = -1 * q.top().first;
		int here = q.top().second;
		q.pop();
		if (P[here] > val)
			continue;
		for (int j = 0; j < adj[here].size(); j++) {
			int there = adj[here][j].first;
			int rode = adj[here][j].second;
			if (P[there] > val + rode) {
				P[there] = val + rode;
				q.push(make_pair(-1 * (val + rode), there));
			}
		}
	}
	if (P[nd] == 1e9) printf("INF\n");
	else printf("%d\n", P[nd]);
}