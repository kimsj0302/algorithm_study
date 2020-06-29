#include<iostream>
#include<algorithm>
using namespace std;
int arr[100001];
int dp[100001];
int main() {
	int num;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= num; i++) {
		if (dp[i - 1] + arr[i] > arr[i]) {
			dp[i] = dp[i - 1] + arr[i];
		}
		else {
			dp[i] = arr[i];
		}
	}
	int m = dp[1];
	for (int i = 2; i <= num; i++) {
		m = max(m, dp[i]);
	}
	printf("%d\n", m);
}