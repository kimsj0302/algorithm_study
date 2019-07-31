#include<iostream>
#define MOD 1000000007 
using namespace std;

long long int fac[4000010];

long long int mul(long long int n, long long int x) {
	if (x == 0)
		return 0;
	if (x == 1)
		return n;
	long long int tmp;
	tmp = mul(n, x / 2);
	if (x % 2 == 0)
		return ((tmp%MOD)*(tmp%MOD)) % MOD;
	else
		return ((((tmp%MOD)*(tmp%MOD)) % MOD)*n) % MOD;
}


int main() {
	fac[0] = 0;
	fac[1] = 1;
	for (int i = 2; i < 4000010; i++) {
		fac[i] = (fac[i - 1] * i)%MOD;
	}
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%lld", (fac[n] * ((mul((fac[k] * fac[n - k]) % MOD, 1000000005)))) % MOD);
}