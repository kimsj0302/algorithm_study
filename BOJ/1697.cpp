#include<iostream>
#include<queue>
using namespace std;
int main() {
	int n, m;
	bool visited[100100];
	
	scanf("%d %d", &n, &m);
	queue<pair<int, int>> que;
	for (int i = 0; i < 100100; i++)
		visited[i] = false;
	que.push(make_pair(n, 0));
	while (!que.empty()) {
		int now = que.front().first, count = que.front().second;
		que.pop();
		if (visited[now])
			continue;
		visited[now] = true;
		if (now == m) {
			printf("%d\n", count);
			return 0;
		}
		if (now > 0)
			que.push(make_pair(now - 1, count + 1));
		if (now < 100000)
			que.push(make_pair(now + 1, count + 1));
		if (now * 2 <= 100000)
			que.push(make_pair(now * 2, count + 1));
	}

}