#include<iostream>
#define M 1000000007
using namespace std;

long long int gcd(long long int a, long long int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

long long int pow(long long int n, int x) {
	if (x == 0)
		return 0;
	if (x == 1)
		return n;
	long long int tmp;
	tmp = pow(n, x / 2);
	if (x % 2 == 0)
		return ((tmp%M)*(tmp%M)) % M;
	else
		return ((((tmp%M)*(tmp%M)) % M)*n) % M;
}
int main() {
	int n;
	scanf("%d", &n);
	long long int result=0;
	for (int i = 0; i < n; i++) {
		long long int a, b;
		scanf("%lld %lld", &b, &a);
		long long int tmp = gcd(a, b);
		b /= tmp;
		a /= tmp;
		result = (result+((a%M)*(pow(b, 1000000005) % M)) % M) % M;
	}



	printf("%lld\n", result);
}