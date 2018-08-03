#include<iostream>
using namespace std;
int dp[10001] = { 0, };

int main() {
	int n;
	scanf("%d", &n);
	for (int x = 0; x < n; x++) {
		int num,m;
		int cost[21] = { 0, };
		for (int i = 0; i <= 10000; i++) {
			dp[i] = 0;
		}
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			scanf("%d", &cost[j]);
		}
		scanf("%d", &m);
		for (int i = 0; i < num; i++) {
			dp[cost[i]]++;
			for (int j = cost[i] + 1; j <= m; j++) {
				dp[j] += dp[j - cost[i]];
			}
		}
		printf("%d\n", dp[m]);
	}
}