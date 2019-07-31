#include<iostream>

int main() {
	int n;
	scanf("%d", &n);
	int answer = 0;
	int out = n;
	do {
		answer++;
		int a, b;
		a = n / 10;
		b = n % 10;
		n = b * 10 + (a + b) % 10;
	} while (out != n);
	printf("%d\n", answer);
}