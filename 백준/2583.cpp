#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dir[4][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };
int arr[101][101];
bool visited[101][101];
int a, b, k;
int dfs(int x, int y) {
	if (arr[x][y] != 0 || x==0 || y==0 || x>a||y>b)
		return 0;
	visited[x][y] = true;
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (!visited[x + dir[i][0]][y + dir[i][1]])
			sum+=dfs(x + dir[i][0], y + dir[i][1]);
	}
	return sum + 1;
}

int main() {
	scanf("%d%d%d", &a, &b, &k);
	for (int i = 0; i <= a; i++)
		for (int j = 0; j <= b; j++) {
			arr[i][j] = 0;
			visited[i][j] = false;
		}
	for (int j = 0; j < k; j++) {
		int x1,y1,x2,y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		for (int x = x1; x < x2; x++)
			for (int y = y1; y < y2; y++)
				arr[y+1][x+1] = 1;
	}
	int answer = 0;
	vector<int> ans;
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++) {
			if (!arr[i][j] && !visited[i][j]) {
				answer++;
				ans.push_back(dfs(i, j));
			}
		}
	printf("%d\n", answer);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
}