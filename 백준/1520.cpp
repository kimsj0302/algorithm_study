#include<iostream>
#include<queue>
using namespace std;
int map[502][502];
int dp[502][502];
bool visited[501][501];
int cal(int x, int y) {
	if (dp[x][y] != -1)
		return dp[x][y];
	dp[x][y] = 0;
	int sum = 0;
	if (x > 0 && map[x - 1][y] < map[x][y])
		sum += cal(x - 1, y);
	if (y > 0 && map[x][y - 1] < map[x][y])
		sum += cal(x, y - 1);
	if (map[x+1][y]!=0 && map[x + 1][y] < map[x][y])
		sum += cal(x + 1, y);
	if (map[x][y+1]!=0 && map[x][y + 1] < map[x][y])
		sum += cal(x, y + 1);
		return dp[x][y] = sum;
}
int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	for(int i=0;i<x;i++)
		for (int j = 0; j < y; j++) {
			dp[i][j] = -1;
			scanf("%d", &map[i][j]);
		}
	dp[x-1][y-1] = 1;

	printf("%d\n", cal(0,0));
}