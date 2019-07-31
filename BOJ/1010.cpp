#include<iostream>
#include<cstring>
using namespace std;
int dp[35][35];
int n, m;
int cal(int num,int hole) {
	if (dp[num][hole] != -1)
		return dp[num][hole];
	if (hole == n) {
		return dp[num][hole]=1;
	}
	int sum = 0;
	for (int i = num+1; i <= m; i++) {
		sum += cal(i, hole + 1);
	}
	return dp[num][hole]=sum;
}

int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 35; j++)
			for (int k = 0; k < 35; k++)
				dp[j][k] = -1;
		scanf("%d %d", &n, &m);
		printf("%d\n", cal(0, 0));
	}
}