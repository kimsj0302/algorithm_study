#include<iostream>
#include<algorithm>
using namespace std;
int DP[1000000];
int cal(int n) {
	if (n < 1000000) {

		if (DP[n] != 0)
			return DP[n];
		if (n % 2 == 0)
			return DP[n] = max(n, cal(n / 2));
		else {
			return DP[n] = max(n, cal(n * 3 + 1));
		}
	}
	else {
		if (n % 2 == 0)
			return max(n, cal(n / 2));
		else {
			return max(n, cal(n * 3 + 1));
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	DP[1] = 1;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		printf("%d\n",cal(tmp));
	}
}