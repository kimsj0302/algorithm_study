#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int num_t[1000][1000];
int dp[101];

int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int N;
		scanf("%d", &N);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				scanf("%d", &num_t[i][j]);
			}
		}
		for (int i = 0; i < 101; i++) {
			dp[i] = 0;
		}
		for (int i = N - 1; i >= 0; i--)
		{
			for (int j = 0; j <= i; j++)
			{
				if (dp[j] >= dp[j + 1]) dp[j] = dp[j] + num_t[i][j];
				else dp[j] = dp[j + 1] + num_t[i][j];
			}
		}

		printf("%d\n", dp[0]);
	}
	return 0;
}