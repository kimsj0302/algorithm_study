#include<iostream>
using namespace std;
long long int dp[21][21][21];
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
	return dp[n][l][r] = ((cal(n - 1, l, r)*(n - 2)) + (cal(n - 1, l - 1, r) + cal(n - 1, l, r - 1)));
}
int main() {
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int n, L, R;
		scanf("%d %d %d", &n, &L, &R);
		for (int i = 0; i < 21; i++)
			for (int j = 0; j < 21; j++)
				for (int k = 0; k < 21; k++)
					dp[i][j][k] = -1;
		printf("%lld\n", cal(n, L, R));
	}
}