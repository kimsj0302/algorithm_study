#include<iostream>
#include<vector>
#include<queue>
using namespace std;



int main() {
	int n,m;
	scanf("%d %d", &n,&m);
	vector<vector<int>> g(n + 1);
	for (int i = 0; i < m; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		g[s].push_back(e);
		g[e].push_back(s);
	}

	int min = 1000000;
	int loc;
	vector<int> dis(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		vector<int> visit(n + 1, 0);
		queue<pair<int, int>> que;
		que.push(make_pair(i, 0));
		int bacon = 0;
		while (!que.empty()) {
			pair<int, int> tmp = que.front();
			que.pop();
			visit[tmp.first] = 1;
			bacon += tmp.second;
			for (int j = 0; j < g[tmp.first].size(); j++)
				if (visit[g[tmp.first][j]] == 0)
					que.push(make_pair(g[tmp.first][j],tmp.second+1));
		}
		if (bacon < min) {
			min = bacon;
			loc = i;
		}
	}
	printf("%d\n", loc);
}