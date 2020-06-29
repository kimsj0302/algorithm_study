#include<iostream>

using namespace std;
long long int dp[91] = { 0, };
long long int fibo(int n) {
	if (n == 1 || n==2)
		return 1;
	if (dp[n] != 0)
		return dp[n];
	return dp[n]=fibo(n - 1) + fibo(n - 2);
}
int main() {
	int num;
	scanf("%d", &num);
	printf("%lld\n", fibo(num));
}