#include<iostream>
#include<algorithm>
using namespace std;
int dp[17][17];
int main() {
	dp[1][1] = 1;
	int n, m,k;
	scanf("%d %d %d", &n, &m,&k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i + 1][j] += dp[i][j];
			dp[i][j + 1] += dp[i][j];
		}
	}
	if (k == 0)
		printf("%d\n", dp[n][m]);
	else {
		int x = 1 + k / m, y = k % m;
		if (y == 0) {
			y = m;
			x--;
		}
		//printf("%d %d\n", x, y);
		printf("%d\n", dp[x][y]*dp[n+1-x][m+1-y]);
	}
}