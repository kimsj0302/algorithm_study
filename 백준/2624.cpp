#include<iostream>
#include<algorithm>
using namespace std;
int dp[10001][101];
pair<int, int> cost[101];
int T, n;
int main() {
	scanf("%d", &T);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		pair<int, int> tmp;
		scanf("%d %d", &tmp.first, &tmp.second);
		cost[i] = tmp;
	}
	sort(cost+1, cost + n + 1);
	for(int i=0;i<n;i++)
		dp[0][i] = 1;
	for (int i = cost[1].first; i <= cost[1].first*cost[1].second; i += cost[1].first) {
		dp[i][1] = 1;
	}
	for (int j = 2; j <= n; j++)
		for (int i = 1; i <= T; i++) {
			for (int k = 0; k <= cost[j].second; k++) {
				if (i - k * cost[j].first < 0)
					continue;
				else {
					dp[i][j] += dp[i - k * cost[j].first][j - 1];
				}
			}
		}
	printf("%d\n", dp[T][n]);
}