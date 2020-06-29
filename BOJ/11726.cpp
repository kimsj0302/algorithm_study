#include<iostream>

using namespace std;
int dp[1001] = { 0, };
int fibo(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (dp[n] != 0)
		return dp[n];
	return dp[n] =( fibo(n - 1) + fibo(n - 2)) % 10007;
}
int main() {
	int num;
	scanf("%d", &num);
	printf("%lld\n", fibo(num) % 10007);
}