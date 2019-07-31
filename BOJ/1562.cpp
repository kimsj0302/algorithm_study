#include<iostream>
#define MOD 1000000000
using namespace std;
int DP[101][10][1<<10];

int main() {
	for (int i = 1; i < 10; i++) {
		DP[1][i][1 << i]=1;
	}
	for (int n = 2; n < 101; n++) {
		for (int i = 0; i < 10; i++) {
			for (int k = 0; k < 1 << 10; k++) {
				if (i != 0) {
					DP[n][i][k | (1 << i)] = (DP[n][i][k | (1 << i)]+DP[n - 1][i - 1][k])%MOD;
				}
				if (i != 9) {
					DP[n][i][k | (1 << i)] = (DP[n][i][k | (1 << i)]+DP[n - 1][i + 1][k])%MOD;
				}
			}
		}
	}
	int n;
	scanf("%d", &n);
		int ans = 0;
		for (int i = 0; i < 10; i++) {
			ans = (ans+DP[n][i][1023])%MOD;
		}
		printf("%d\n",  ans);
}