#include<iostream>

using namespace std;
int DP[1001][10];


int main() {
	int num;
	scanf("%d", &num);
	for (int i = 1; i <= num;i++) {
		DP[i][0] = 1;
	}
	for (int i = 0; i < 10; i++) {
		DP[1][i] = 1;
	}
	for (int i = 2; i <= num; i++) {
		for (int j = 1; j < 10; j++) {
			int sum = 0;
			for (int k = 0; k <= j; k++) {
				sum = (sum + DP[i - 1][k]) % 10007;
			}
			DP[i][j] = sum;
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans = (ans + DP[num][i]) % 10007;
	}
	printf("%d\n", ans);
}