#include<iostream>

using namespace std;

int main() {
	long long int n, m, k;
	scanf("%lld %lld %lld", &n, &m, &k);
	if (k < n) {
		printf("%lld 1\n", 1 + k);
		return 0;
	}
	k -= n;
	m--;
	long long int hi = k / (2 * m);
	long long int we = k % (2 * m);
	if (we < m) {
		printf("%lld %lld\n", n - 2 * hi, 2 + we);
	}
	else
		printf("%lld %lld\n", n - 2 * hi - 1, 2 * m + 1 - we);
}