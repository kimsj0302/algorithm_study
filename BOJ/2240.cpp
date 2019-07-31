#include<iostream>
#include<algorithm>
using namespace std;
int dp[1001][31][2];
int arr[1001];
int T, W;

int cal(int n, int w, int p) {
	if (n == 0)
		return 0;
	if (dp[n][w][p] != 0)
		return dp[n][w][p];
	if (0 == w)
		return cal(n - 1, w, p)+(arr[n]==p+1);
	else {
		return dp[n][w][p]=(arr[n]==p+1)+max(cal(n - 1, w, p), cal(n - 1, w - 1, 1 - p));
	}
}

int main() {
	scanf("%d %d", &T, &W);
	for (int i = 1; i <= T; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr[i] = tmp;
	}
	if (arr[0] == 1)
		dp[1][0][0] = 1;
	else
		dp[1][1][1] = 1;
	printf("%d\n", max(cal(T, W, 0),cal(T,W-1,1)));
}