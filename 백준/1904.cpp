#include<iostream>

using namespace std;
int dp[1000001];
int fibo(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (dp[n] != 0)
		return dp[n];
	return dp[n] = (fibo(n - 1) + fibo(n - 2)) % 15746;
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", fibo(n));
}