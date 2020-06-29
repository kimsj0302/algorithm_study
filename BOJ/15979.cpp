#include<iostream>
using namespace std;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (a == 0 && b == 0) {
		printf("0\n");
		return 0;
	}
	if ((a == 1 && b == 0) || (a == 0 && b == 1)) {
		printf("1\n");
		return 0;
	}
	if (a == 0 || b == 0) {
		printf("2\n");
		return 0;
	}
	if (b > a) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (gcd(a, b) == 1)
		printf("1\n");
	else
		printf("2\n");
}