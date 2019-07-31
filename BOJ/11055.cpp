#include<iostream>

using namespace std;
int arr[1001];
int dp[1001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
	}
	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		int ma = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (dp[j]> ma)
					ma = dp[j];
			}
		}
		dp[i] = ma+arr[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		//printf("%d ", dp[i]);
		if (ans < dp[i])
			ans = dp[i];
	}
	printf("%d\n", ans);
}