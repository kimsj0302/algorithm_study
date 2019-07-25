#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int, int>> adj[20001];
int V, E;
long long int run(int st,int nd) {

	vector<long long int> P(V + 2, 1e13);
	priority_queue<pair<int, int>> q;

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
	return P[nd];
}
int main() {
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	int p1,p2;
	scanf("%d %d", &p1,&p2);
	long long int way1 = run(1, p1) + run(p1, p2) + run(p2, V);
	long long int way2 = run(1, p2) + run(p2, p1) + run(p1, V);
	long long int m = way1;
	if (way2 < 1e13 && way2 < way1)
		m = way2;
	printf("%lld\n", m >= 1e13 ?-1:m);
}