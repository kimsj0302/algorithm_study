#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 500000
using namespace std;


vector<int> arr;
int dp[51][MAX];


int main() {
	int n;
	cin >> n;
	int t = n;
	arr.push_back(0);
	while (t-- > 0) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	for (int i = 0; i < 51; i++) for (int j = 0; j < MAX; j++) dp[i][j] = -1;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < MAX; j++) {
			dp[i][j] = dp[i-1][j];
			if (j + arr[i] < MAX && dp[i - 1][j + arr[i]]!=-1)
				dp[i][j] = max(dp[i][j], dp[i - 1][j + arr[i]]);
			if (j - arr[i] >= 0 && dp[i - 1][j - arr[i]]!=-1)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[i]] + arr[i]);
			if (arr[i] - j >= 0 && dp[i - 1][arr[i] - j] != -1)
				dp[i][j] = max(dp[i][j], dp[i - 1][arr[i] - j] + j);
		}
	}
	printf("%d",  dp[n][0] ? dp[n][0] : -1);
}