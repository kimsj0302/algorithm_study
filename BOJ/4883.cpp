#include<iostream>
#include<algorithm>
using namespace std;
int arr[3][100001];
long long int dp[3][100001];
int main() {
	int num = 1;
	while (1) {
		
		int n;
		scanf("%d", &n);
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &arr[0][i], &arr[1][i], &arr[2][i]);
		}
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[2][0] = arr[2][0]+arr[1][0];
		for (int i = 1; i < n; i++) {
			if (i == 1) {
				dp[0][1] = arr[0][1] + dp[1][0];
				dp[1][1] = arr[1][1] + min(min(dp[1][0],dp[2][0]),dp[0][1]);
				dp[2][1] = arr[2][1] + min(min(dp[1][0], dp[2][0]), dp[1][1]);
			}
			else {
				dp[0][i] = arr[0][i] + min(dp[0][i - 1], dp[1][i - 1]);
				dp[1][i] = arr[1][i] + min(min(min(dp[0][i - 1], dp[1][i - 1]), dp[2][i - 1]),dp[0][i]);
				dp[2][i] = arr[2][i] + min(min(dp[2][i - 1], dp[1][i - 1]),dp[1][i]);
			}
		}
		printf("%d. %lld\n",num++, dp[1][n - 1]);
	}
}
