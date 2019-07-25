#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct ele {
	int x, y, num;
	ele(int a, int b, int c) :x(a), y(b), num(c) {};
};
bool operator<(const struct ele &a, const struct ele &b) {
	return a.num > b.num;
}
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main() {
	int pnum = 1;
	while (1) {
		int n;
		scanf("%d", &n);
		if (n == 0)
			break;
		int arr[126][126];
		int result[126][126];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
				result[i][j] = 1e9;
			}
		priority_queue<struct ele> que;
		struct ele st(0, 0, arr[0][0]);
		result[0][0] = arr[0][0];
		que.push(st);
		while (!que.empty()) {
			struct ele tmp = que.top();
			int tx = 1, ty = 1;
			que.pop();
			for (int i = 0; i < 4; i++) {
				if (tmp.x + dx[i] < 0 || tmp.x + dx[i] >= n || tmp.y + dy[i] < 0 || tmp.y + dy[i] >= n)
					continue;
				if (result[tmp.x+dx[i]][tmp.y+dy[i]] > arr[tmp.x + dx[i]][tmp.y + dy[i]] + tmp.num) {
					struct ele t(tmp.x + dx[i], tmp.y + dy[i], arr[tmp.x + dx[i]][tmp.y + dy[i]] + tmp.num);
					que.push(t);
					result[tmp.x + dx[i]][tmp.y + dy[i]] = arr[tmp.x + dx[i]][tmp.y + dy[i]] + tmp.num;
					tx = tmp.x + dx[i];
					ty = tmp.y + dy[i];
					if (tx == n - 1 && ty == n - 1)
						break;
				}
			}
			if (tx == n - 1 && ty == n - 1)
				break;
		}
		printf("Problem %d: %d\n", pnum++,result[n - 1][n - 1]);
	}
}