#include<iostream>
#include<algorithm>
#define INF 200000000
using namespace std;
int dp[501][501];
int sum[501];
int arr[501];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		for (int j = 1; j <= num; j++) {	
			scanf("%d", &arr[j]);
			sum[j] = sum[j - 1] + arr[j];
		}
		for (int d = 1; d < num; ++d) {
			for (int x = 1; x + d <= num; ++x) {
				int y = x + d;
				dp[x][y] = INF;
				for (int mid = x; mid < y; mid++) {
					dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid + 1][y] + sum[y] - sum[x - 1]);
				}
			}
		}
		printf("%d\n", dp[1][num]);
	}
}