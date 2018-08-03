#include<stdio.h>
long long int a[1000001] = { 0,1,1, };
long long int fibo(int n) {
	if (n<2)
		return a[n];
	if (a[n] != 0)
		return a[n];
	else
		a[n] = (fibo(n - 1) + fibo(n - 2))%1000000007;
	return a[n];
}

int main() {
	int num;
	scanf("%d", &num);
	printf("%lld\n", fibo(num));
} 