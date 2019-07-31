#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dp[1001];
int main() {
	vector<int> arr;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		//printf("%d ", dp[i]);
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
}