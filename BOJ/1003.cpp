#include<iostream>
#include<cstring>
using namespace std;
int dp1[41] = { 0, };
int dp0[41] = { 0, };
void fibo(int n) {
	if (n == 0) {
		dp0[n] = 1;
		dp1[n] = 0;
		return;
	}
	else if (n == 1) {
		dp1[n] = 1;
		dp0[n] = 0;
		return;
	}
	else {
		if (dp0[n] != 0)
			return;
		fibo(n-2);
		fibo(n - 1);
		dp1[n] = dp1[n - 2] + dp1[n - 1];
		dp0[n] = dp0[n - 2] + dp0[n - 1];
	}
	return;
}
int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int tmp;
		scanf("%d", &tmp);
		memset(dp1, 0, sizeof(dp1));

		memset(dp0, 0, sizeof(dp0));
		fibo(tmp);
		printf("%d %d\n", dp0[tmp], dp1[tmp]);
	}
}