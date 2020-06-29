#include<iostream>
#define MOD 1000000000
using namespace std;
long long int dp[10][101];
int main() {
	int num;
	scanf("%d", &num);
	for (int i = 1; i <= 9; i++) {
		dp[i][1] = 1;
	}

	for (int i = 1; i <= num; i++) {
		for (int j = 0; j <= 9; j++) {
			if (dp[j][i] == 0)
				continue;
			else {
				int up, down;
				up = j + 1;
				down = j - 1;
				if (up <= 9) {
					dp[up][i + 1] = (dp[j][i]+dp[up][i + 1])%MOD;
				}
				if (down >= 0) {
					dp[down][i + 1] = (dp[j][i]+dp[down][i + 1])%MOD;
				}
			}
		}
	}
	long long int sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += dp[i][num];
		sum %= MOD;
	}
	printf("%lld\n", sum%MOD);
}