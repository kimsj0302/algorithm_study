#include<iostream>
#include<algorithm>
using namespace std;
int arr[1005];
int dp[1005];
int cal(int num) {
	if (dp[num] != 0)
		return dp[num];
	int m = 0;
	for (int i = 1; i <= num; i++) {
		m = max(m, arr[i] + cal(num-i));
	}
	return dp[num]=m;
}
int main() {
	int boong;
	scanf("%d", &boong);
	for (int i = 1; i <= boong; i++) {
		scanf("%d", &arr[i]);
	}
	dp[1] = arr[1];
	printf("%d\n", cal(boong));
}