#include<iostream>

using namespace std;
long long int dp[70];
long long int fibo(int n) {
	if (n < 2)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 4;
	if (dp[n] != 0)
		return dp[n];
	return dp[n] = fibo(n-1)+fibo(n-2)+fibo(n-3)+fibo(n-4);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		printf("%lld\n", fibo(num));
	}
}