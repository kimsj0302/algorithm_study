#include<iostream>

using namespace std;

int main() {
	int n, num;
	scanf("%d %d", &n, &num);
	long long int st = 0, nd = 10000000010;
	long long int min = nd;
	while (st != nd) {
		long long int mid = (st + nd) / 2;
		long long int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += (mid / i > n ? n : mid / i);
		}
		if (sum >= num) {
			nd = mid;
			if (min > mid)
				min = mid;
		}
		else {
			st = mid + 1;
		}
	}
	printf("%lld\n", min);
}