#include<iostream>
#define MOD 1000000000
using namespace std;
long long int dp[201][201];

long long int cal(int n, int k) {
	if (k == 1 || n == 0)
		return dp[n][k] = 1;
	if (dp[n][k] != 0)
		return dp[n][k];
	int sum = 0;
	for (int i = 0; i <= n; i++) {
		sum = (sum + cal(n - i, k - 1)) % MOD;
	}
	return dp[n][k] = sum % MOD;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	printf("%lld\n", cal(n, k)%MOD);
}