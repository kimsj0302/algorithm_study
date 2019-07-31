#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int min6=2000, min1=2000;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a < min6)
			min6 = a;
		if (b < min1)
			min1 = b;
	}
	int sum;
	if (min6 > min1 * 6) {
		sum = n * min1;
	}
	else {
		sum = n / 6 * min6;
		n = n % 6;
		if (min6 > n*min1) {
			sum += n * min1;
		}
		else {
			sum += min6;
		}
	}
	printf("%d\n", sum);
}