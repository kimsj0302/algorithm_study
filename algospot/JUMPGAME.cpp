#include<iostream>

using namespace std;
int arr[101][101];
int can[101][101];
int n;
bool cal(int x, int y) {
	if (x == n && y == n)
		return true;
	if (x > n || y > n || x < 1 || y < 1)
		return false;
	//printf("[%d %d: %d]", x, y,arr[x][y]);
	if (can[x][y] != 0) {
		if (can[x][y] == 1)
			return true;
		else
			return false;
	}
	if (cal(x + arr[x][y], y)) {
		can[x][y] = 1;
		return true;
	}
	if (cal(x, y + arr[x][y])) {
		can[x][y] = 1;
		return true;
	}
	can[x][y] = -1;
	return false;
}
int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int tmp;
				scanf("%d", &tmp);
				can[i][j] = 0;
				arr[i][j] = tmp;
			}
		}
		can[n][n] = 1;
		if (cal(1, 1))
			printf("YES\n");
		else
			printf("NO\n");
	}
}