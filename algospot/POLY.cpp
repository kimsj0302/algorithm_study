#include<iostream>
#define MOD 10000000
using namespace std;
int DP[101][101];
int poly(int n, int under) {
	if (n == under) return 1;
	if (DP[n][under] != -1) return DP[n][under];
	int sum = 0;
	for (int i = 1; i <= n - under; i++) {
		int add = i + under - 1;
		add *= poly(n - under, i);
		add %= MOD;
		sum += add;
		sum %= MOD;
	}
	return DP[n][under]=sum;
}
int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int k;
		scanf("%d", &k);
		for (int i = 0; i < 101; i++)
			for (int j = 0; j < 101; j++)
				DP[i][j] = -1;
		int sum = 0;
		for (int i = 1; i <= k; i++) {
			sum += poly(k, i);
			sum %= MOD;
		}
		cout<<sum<<endl;
	}
}