#include<iostream>
#include<algorithm>
using namespace std;
int arr[1201];
int dp[1201];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		dp[i] = 2000;
	}
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= arr[i]; j++) {
			dp[i + j] = min(dp[i] + 1, dp[i + j]);
		}
	}
	if (dp[n - 1] == 2000)
		printf("-1\n");
	else
		printf("%d\n", dp[n - 1]);
}