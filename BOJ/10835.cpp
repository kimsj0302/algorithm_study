#include<iostream>
#include<algorithm>
using namespace std;
int dp[2011][2011];
int leftd[2011];
int rightd[2011];
	int n;
int cal(int left, int right) {
	if (right == n || left == n)
		return 0;
	if (dp[left][right] != -1)
		return dp[left][right];
	int re=max(cal(left + 1, right + 1), cal(left + 1, right));
	if (rightd[right] < leftd[left]) {
		re = max(re,cal(left, right + 1) + rightd[right]);
	}
	return dp[left][right]=re;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &leftd[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &rightd[i]);
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++)
			dp[i][j] = -1;
	}
	printf("%d\n", 	cal(0, 0));
}