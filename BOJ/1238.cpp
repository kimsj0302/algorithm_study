#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main() {
		int n,m,s;
		scanf("%d %d %d", &n,&m,&s);
		vector<vector<pair<int, int>>> arr(n+1);
		for (int i = 0; i < m; i++) {
			int st, nd, we;
			scanf("%d %d %d", &st, &nd, &we);
			arr[st].push_back(make_pair(we, nd));
		}
		vector < vector<int>> re(n+1);
		for (int i = 1; i <= n; i++) {
			priority_queue<pair<int, int>> que;
			que.push(make_pair(0,i));
			vector<int> result(n + 1, 1e9);
			result[i] = 0;
			while (!que.empty()) {
				pair<int,int> tmp = que.top();
				que.pop();
				for (int j = 0; j < arr[tmp.second].size(); j++) {
					if (-1 * tmp.first + arr[tmp.second][j].first < result[arr[tmp.second][j].second]) {
						result[arr[tmp.second][j].second] = -1 * tmp.first + arr[tmp.second][j].first;
						que.push(make_pair(-1 * result[arr[tmp.second][j].second], arr[tmp.second][j].second));
					}
				}
			}
			re[i]=result;
		}
		int max = 0;
		for (int i = 1; i <= n; i++) {
			if (max < re[i][s] + re[s][i])
				max = re[i][s] + re[s][i];
		}
		printf("%d\n", max);
}