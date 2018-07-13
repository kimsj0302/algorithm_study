#include<iostream>

using namespace std;
long long int dp[1001] = { 0, };
long long int fibo(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 3;
	if (dp[n] != 0)
		return dp[n];
	return dp[n] = (fibo(n - 1) + 2 * fibo(n - 2)) % 10007;
}
int main() {
	int num;
	scanf("%d", &num);
	printf("%lld\n", fibo(num) % 10007);
}