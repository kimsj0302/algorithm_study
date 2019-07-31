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
		int n,m;
		scanf("%d %d", &m,&n);
		int arr[126][126];
		int result[126][126];
		for (int i = 0; i<n; i++) {
			for (int j = 0; j< m; j++) {
				char a;
				scanf("%c", &a);
				if (a == '\n')
					scanf("%c", &a);
				arr[i][j] = (a == '0' ? 0 : 1);
				result[i][j] = 1e9;
			}
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
				if (tmp.x + dx[i] < 0 || tmp.x + dx[i] >= n || tmp.y + dy[i] < 0 || tmp.y + dy[i] >= m)
					continue;
				if (result[tmp.x+dx[i]][tmp.y+dy[i]] > arr[tmp.x + dx[i]][tmp.y + dy[i]] + tmp.num) {
					struct ele t(tmp.x + dx[i], tmp.y + dy[i], arr[tmp.x + dx[i]][tmp.y + dy[i]] + tmp.num);
					que.push(t);
					result[tmp.x + dx[i]][tmp.y + dy[i]] = arr[tmp.x + dx[i]][tmp.y + dy[i]] + tmp.num;
				}
			}
		}
		printf("%d\n", result[n - 1][m - 1]);
}