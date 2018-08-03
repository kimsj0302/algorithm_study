#include<iostream>
#define MOD 1000000007
using namespace std;
long long int dp[101][101][101];
long long int cal(int n, int l, int r) {
	if (n == 1) {
		if (l == 1 && r == 1)
			return 1;
		else
			return 0;
	}
	if (n == r && l == 1)
		return 1;
	if (n == l && r == 1)
		return 1;
	
	if (dp[n][l][r] != -1)
		return dp[n][l][r];
	return dp[n][l][r]=((cal(n - 1, l, r)*(n - 2)) % MOD + (cal(n - 1, l - 1, r) + cal(n - 1, l, r - 1)) % MOD) % MOD;
}
int main() {
	int n, L, R;
	scanf("%d %d %d", &n, &L, &R);
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			for (int k = 0; k < 101; k++)
				dp[i][j][k] = -1;
	printf("%lld\n", cal(n, L, R));
}