#include<stdio.h>

int fibo(int n) {
	int static a[45];
	if (n == 1 || n == 2)
		return 1;
	if (a[n - 1] != 0)
		return a[n - 1];
	else
		a[n - 1] = fibo(n - 1) + fibo(n - 2);
	return fibo(n - 1) + fibo(n - 2);
}

int main() {
	int num;
	scanf("%d", &num);
	printf("%d", fibo(num));
}