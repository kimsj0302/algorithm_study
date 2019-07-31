#include<iostream>

int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int arr[51][51];
bool visited[51][51];

void dfs(int x, int y) {
	if (arr[x][y] == 0)
		return;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		if(!visited[x + dir[i][0]][ y + dir[i][1]])
			dfs(x + dir[i][0], y + dir[i][1]);
	}

}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b,k;
		scanf("%d%d%d", &a, &b,&k);
		for (int i = 0; i <= a; i++)
			for (int j = 0; j <= b; j++) {
				arr[i][j] = 0;
				visited[i][j] = false;
			}
		for (int j = 0; j < k; j++) {
			int q, w;
			scanf("%d %d", &q, &w);
			arr[q+1][w+1] = 1;
		}
		int answer = 0;
		for (int i = 1; i <= a; i++)
			for (int j = 1; j <= b; j++) {
				if (arr[i][j] && !visited[i][j]) {
					answer++;
					dfs(i, j);
				}
			}
		printf("%d\n", answer);
	}
}