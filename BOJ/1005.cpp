#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		vector<vector<int > > graph(1001);
		queue<int > que;
		int before[1001];
		int delay[1001];
		int can[1001];
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			before[i] = 0;
			delay[i] = 0;
			can[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			cin >> delay[i];
		}
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			graph[a - 1].push_back(b - 1);
			can[b - 1]++;
		}
		for (int i = 0; i < n; i++) {
			if (!can[i]) {
				before[i] = delay[i];
				que.push(i);
			}
		}

		while (!que.empty()) {
			int tmp = que.front();
			que.pop();
			for (auto g : graph[tmp]) {

				before[g] = max(before[tmp]+delay[g], before[g]);
				if (--can[g]==0) {
					que.push(g);
					can[g] = 1;

				}
			}

		}
		int target;
		cin >> target;
		cout << before[target - 1] << "\n";
	}
}