#include<iostream>

using namespace std;
long long int dp[65][10];
int main() {
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int n = 2; n <= 64; n++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j <= i; j++) {
				dp[n][i] += dp[n - 1][j];
			}
		}
	}
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int tmp;
		scanf("%d", &tmp);
		long long int ans = 0;
		for (int j = 0; j < 10; j++) {
			ans += dp[tmp][j];
		}
		printf("%lld\n", ans);
	}
}