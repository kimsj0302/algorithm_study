#include<iostream>

using namespace std;

int main() {
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int a;
		long long int  ans = 1;
		scanf("%d", &a);
		for (long long int i = 2; i <= a; i++) {
			int mul = i;
			while (mul % 10 == 0) {
				mul /= 10;
			}
			ans *= i;
			while (ans % 10 == 0) {
				ans /= 10;
			}
			ans %= 100000;
		}
		printf("%lld\n", ans % 10);
	}
}