#include<iostream>
#include<cstring>
#define MOD 1000000007
using namespace std;
long long int dp[105];
long long int tiling(int n) {
	if (dp[n] != 0)
		return dp[n];
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	return dp[n]=(tiling(n - 1) % MOD + tiling(n - 2) % MOD) % MOD;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		memset(dp, 0, 103);
		int num;
		scanf("%d", &num);
		printf("%lld\n", tiling(num)%MOD);
	}
}