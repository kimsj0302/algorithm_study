#include<iostream>

using namespace std;

int arr[301][301];
int DP[301][301];
int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= y; j++)
			scanf("%d", &arr[i][j]);
	DP[1][1] = arr[1][1];
	for (int i = 2; i <= x; i++)
		DP[i][1] = DP[i - 1][1] + arr[i][1];
	for (int j = 2; j <= y; j++)
		DP[1][j] = DP[1][j - 1] + arr[1][j];
	for (int i = 2; i <= x; i++)
		for (int j = 2; j <= y; j++)
			DP[i][j] = arr[i][j]+DP[i][j - 1] + DP[i - 1][j] - DP[i - 1][j - 1];




	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int x1, x2, y1, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", DP[x2][y2] - DP[x2][y1 - 1] - DP[x1 - 1][y2] + DP[x1 - 1][y1 - 1]);
	}

}