#include<iostream>

using namespace std;
int dp[1001][1001];
int cal(int n, int r) {
	if (n == r || r == 0)
		return dp[n][r] = 1;
	if (dp[n][r] != 0)
		return dp[n][r];
	return dp[n][r] = (cal(n - 1, r - 1) + cal(n - 1, r))%10007;
}

int main() {
	int n, r;
	scanf("%d %d", &n, &r);
	printf("%d\n", cal(n, r) % 10007);
}