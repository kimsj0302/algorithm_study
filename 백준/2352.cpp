#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dp[40001];
int main() {
	vector<int> arr;
	int n;
	scanf("%d", &n);
	arr.push_back(0);
	for (int i = 1; i <= n; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}
	int i, it;
	dp[1] = arr[1];
	int size = 1;
	for (int i = 2; i <= n; i++) {
		if (dp[size] < arr[i]) {
			size++;
			dp[size] = arr[i];
			continue;
		}
		it = lower_bound(dp + 1, dp + size + 1, arr[i]) - dp;
		dp[it] = arr[i];
	}
	printf("%d\n", size);
}