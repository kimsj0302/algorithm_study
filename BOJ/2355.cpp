#include<iostream>

using namespace std;

int main() {
	long long int st, nd;
	scanf("%lld %lld", &st, &nd);
	if (st > nd) {
		long long int tmp;
		tmp = st;
		st = nd;
		nd = tmp;
	}
	long long int sum = 0;
	if (st < 0) {
		sum -= ((-st + 1)*(-st)) / 2;
	}
	else {
		sum -= ((st - 1)*st) / 2;
	}

	if (nd < 0) {
		sum += ((-nd)*(-nd-1)) / 2;
	}
	else {
		sum += ((nd + 1)*nd) / 2;
	}
	printf("%lld\n", sum);
}