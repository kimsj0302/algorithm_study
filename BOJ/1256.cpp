#include<iostream>
#include<algorithm>
using namespace std;
long long int dp[101][101];
void cal(int n,int m ,int k) {
	//printf("[%d %d %d]\n", n, m, k);
	if (n == 0) {
		for (int i = 1; i <= m; i++)
			printf("z");
		return;
	}
	if (m == 0) {
		for (int i = 1; i <= n; i++)
			printf("a");
		return;
	}
	if (k<=dp[n-1][m]) {
		printf("a");
		cal(n - 1, m, k);
	}
	else if(k<1000000001){
		printf("z");
		cal(n, m-1, k - dp[n - 1][m]);
		
	}
	else {
		printf("-1");
		return;
	}
}
int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0;i<101;i++)
		for (int j = 0; j < 101; j++) {
			if (i == 0 && j == 0) continue;
			if (i == 0)
				dp[i][j] = 1;
			else if (j == 0)
				dp[i][j] = 1;
			else {
				dp[i][j] = min(dp[i - 1][j] + dp[i][j - 1], (long long int)1000000001);
			}
		}
	if (k > dp[n][m]) {
		printf("-1\n");
		return 0;
	}
	else {
		cal(n,m,k);
		printf("\n");
	}
}