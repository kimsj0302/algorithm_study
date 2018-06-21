#include<iostream>
#include<cstring>
#define MOD 1000000007
using namespace std;
long long int dp[105];
long long int tiling(int n) {
	if (n == 0)
		return 0;
	if (dp[n] != 0)
		return dp[n];
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	return dp[n] = (tiling(n - 1) % MOD + tiling(n - 2) % MOD) % MOD;
}
long long int asymmetric(int width) {
	if (width % 2 == 1)
		return (tiling(width) - tiling(width / 2) + MOD) % MOD;
	long long int  tmp = tiling(width);
	tmp = (MOD + tmp - tiling(width / 2)) % MOD;
	tmp = (MOD + tmp - tiling(width / 2-1)) % MOD;
	return tmp;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		memset(dp, 0, 103);
		int num;
		scanf("%d", &num);
		if (num == 2)
			printf("0\n");
		else
			printf("%lld\n", asymmetric(num) % MOD);
	}
}