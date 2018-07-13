#include<iostream>
#include<algorithm>
using namespace std;
int dp[302][302];
int cal(int n, int m) {
	if (n == 1 && m == 1)
		return 0;
	if (dp[n][m] != 0)
		return dp[n][m];
	int mi = 200000;
	if (n >= 2) {
		mi = min(mi, 1 + cal(n / 2, m) + cal(n - n / 2, m));
	}
	if (m >= 2) {
		mi = min(mi, 1 + cal(n, m / 2) + cal(n, m - m / 2));
	}
	return dp[n][m]=mi;
}
int main() {
	int n, m;
	dp[2][1] = 1;
	dp[1][2] = 1;

	scanf("%d %d", &n, &m);
	printf("%d", cal(n, m));
}