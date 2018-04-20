#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<pair<int, int> > > g(n + 1);
	vector<int> check(n + 1, 1e9);
	bool cycle = false;
	for (int i = 0; i < m; i++) {
		int st, nd, cost;
		scanf("%d %d %d", &st, &nd, &cost);
		g[st].push_back({ nd, cost });
	}
	check[1] = 0;
	for (int j = 0; j < n; j++) {
		for (int i = 1; i <= n; i++) {
			for (int k = 0; k < g[i].size(); k++) {
				int next = g[i][k].first;
				int cost = g[i][k].second;

				if (check[i] != 1e9 && check[next] > check[i] + cost) {
					check[next] = check[i] + cost;
					if (j == n - 1)cycle = true;
				}
			}
		}
	}
	if (cycle)printf("-1\n");
	else
		for (int i = 2; i <= n; i++) printf("%d\n", check[i] != 1e9 ? check[i] : -1);
}