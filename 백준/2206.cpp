#include<iostream>
#include<queue>
using namespace std;
int arr[1001][1001];
int reach[1001][1001][2];
int visit[1001][1001][2];
int n, m;

struct ele {
	int x;
	int y;
	int num;
	int use;
};

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			char a;
			scanf("%c", &a);
			if (a == '\n')
				scanf("%c", &a);
			arr[i][j] = (a == '0' ? 0 : 1);
		}
	}

	struct ele f;
	f.x = 0;
	f.y = 0;
	f.num = 1;
	f.use = 0;
	queue<struct ele> que;
	que.push(f);
	visit[0][0][0] = 1;
	while (!que.empty()) {
		struct ele tmp = que.front();
		que.pop();
		int x = tmp.x;
		int y = tmp.y;
		int num = tmp.num;
		int use = tmp.use;
		reach[x][y][use] = num;
		if (x == n - 1 && y == m -1)
			break;
		struct ele ne;
		if (x>0 && visit[x - 1][y][use] == 0 && arr[x - 1][y] == 0) {
			ne.x = x - 1;
			ne.y = y;
			ne.num = num + 1;
			ne.use = use;
			visit[ne.x][ne.y][ne.use] = 1;
			que.push(ne);
		}
		if (y>0 && visit[x][y - 1][use] == 0 && arr[x][y - 1] == 0) {
			ne.x = x;
			ne.y = y - 1;
			ne.num = num + 1;
			ne.use = use;
			visit[ne.x][ne.y][ne.use] = 1;
			que.push(ne);
		}

		if (x<n - 1 && visit[x + 1][y][use] == 0 && arr[x + 1][y] == 0) {
			ne.x = x + 1;
			ne.y = y;
			ne.num = num + 1;
			ne.use = use;
			visit[ne.x][ne.y][ne.use] = 1;
			que.push(ne);
		}

		if (y<m - 1 && visit[x][y + 1][use] == 0 && arr[x][y + 1] == 0) {
			ne.x = x;
			ne.y = y + 1;
			ne.num = num + 1;
			ne.use = use;
			visit[ne.x][ne.y][ne.use] = 1;
			que.push(ne);
		}


		if (!use && x>1 && visit[x - 2][y][use] == 0 && arr[x - 2][y] == 0) {
			ne.x = x - 2;
			ne.y = y;
			ne.num = num + 2;
			ne.use = 1;
			visit[ne.x][ne.y][ne.use] = 1;
			que.push(ne);
		}
		if (!use && y>1 && visit[x][y - 2][use] == 0 && arr[x][y-2] == 0) {
			ne.x = x;
			ne.y = y - 2;
			ne.num = num + 2;
			ne.use = 1;
			visit[ne.x][ne.y][ne.use] = 1;
			que.push(ne);
		}

		if (!use && x<n - 2 && visit[x + 2][y][use] == 0 && arr[x + 2][y] == 0) {
			ne.x = x + 2;
			ne.y = y;
			ne.num = num + 2;
			ne.use = 1;
			visit[ne.x][ne.y][ne.use] = 1;
			que.push(ne);
		}

		if (!use && y<m - 2 && visit[x][y + 2][use] == 0 && arr[x][y+2] == 0) {
			ne.x = x;
			ne.y = y + 2;
			ne.num = num + 2;
			ne.use = 1;
			visit[ne.x][ne.y][ne.use] = 1;
			que.push(ne);
		}
	}
	int result = reach[n - 1][m - 1][1];
	if (result < reach[n - 1][m - 1][0] && reach[n - 1][m - 1][0]!=0)
		result = reach[n - 1][m - 1][0];
	printf("%d\n", result == 0 ? -1 : result);
}
