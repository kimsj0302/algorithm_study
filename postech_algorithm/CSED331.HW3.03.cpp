#include<iostream>
#include<queue>
#include<vector>

using namespace std;






int main() {
	int num;
	scanf("%d", &num);
	for (int j = 0; j < num; j++) {
		vector<pair<int, int> > adj[20001];
		priority_queue<pair<int, int> >q;
		int i;
		int V, E;
		scanf("%d %d", &V, &E);
		for (int i = 0; i < E; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			adj[u].push_back(make_pair(v, w));
			adj[v].push_back(make_pair(u, w));
		}
		vector<int> P(V + 1, 1e9);
		vector<int> rode_map(V + 1, 0);
		P[0] = 0;
		q.push(make_pair(0, 0));

		while (!q.empty()) {
			int brode = -1 * q.top().first;
			int here = q.top().second;
			q.pop();
			if (rode_map[here] <= brode) continue;
			for (i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i].first;
				int rode = adj[here][i].second;
				if (P[there]> P[here] + rode && rode > brode) {
					q.push(make_pair(-1 * rode, there));
					P[there] = P[here] + rode;
					rode_map[there] = rode;
				}
			}
		}
		if (P[V - 1] == 1e9) printf("-1\n");
		else printf("%d\n", P[V - 1]);
	}
}