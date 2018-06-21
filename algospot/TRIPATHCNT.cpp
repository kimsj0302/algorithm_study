#include<iostream>
#include<cstring>
int a[101][101];
int f[101][101];
int way[101][101];
int max(int a, int b)
{
	return a > b ? a : b;
}
int DP(int i, int j) {
	if (way[i][j] != 0)
		return way[i][j];
	if (f[i + 1][j] == f[i + 1][j + 1])
		return way[i][j]=DP(i + 1, j) + DP(i + 1, j + 1);
	if (f[i + 1][j] > f[i + 1][j + 1])
		return way[i][j] = DP(i + 1, j);
	return way[i][j] = DP(i + 1, j + 1);
}
int main()
{
	int numcases;
	scanf("%d", &numcases);
	int N;
	for (int i = 0; i < numcases; ++i)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= i; ++j)
			{
				scanf("%d", &a[i][j]);
			}
		}

		for (int i = 1; i <= N; ++i)
		{
			f[N][i] = a[N][i];
		}

		for (int i = N - 1; i > 0; --i)
		{
			for (int j = 1; j <= i; ++j)
			{
				f[i][j] = a[i][j] + max(f[i + 1][j], f[i + 1][j + 1]);
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				way[i][j] = 0;
			}
		}
		for (int i = 1; i <= N; i++) {
			way[N][i] = 1;
		}
		DP(1, 1);
		std::cout << way[1][1] << std::endl;

	}
}