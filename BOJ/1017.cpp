#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int prime[3000];


int level[100];
int c[100][100], f[100][100];
vector<int> graph[100];
int work[100];
int S, E;

void cal() {
	for (int i = 0; i < 3000; i++) {
		prime[i] = 1;
	}
	prime[0] = 0;
	prime[1] = 0;
	for (int i = 2; i < 3000; i++) {
		for (int j = i + 1; j < 3000; j++) {
			if (j % i == 0)
				prime[j] = 0;
		}
	}
}

bool bfs() {
	for (int i = 0; i < 100; i++) level[i] = -1;
	level[S] = 0;
	queue<int> que;
	que.push(0);
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			if (level[next] == -1 && c[now][next] - f[now][next] > 0) {
				level[next] = level[now] + 1;
				que.push(next);
			}
		}
	}
	return level[E] != -1;
}

int dfs(int now, int flow) {
	if (now == E) return flow;
	for (int& i = work[now]; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (level[now] + 1 == level[next] && c[now][next] - f[now][next] > 0) {
			int re = dfs(next, min(flow, c[now][next] - f[now][next]));
			if (re > 0) {
				f[now][next] += re;
				f[next][now] -= re;
				return re;
			}
		}
	}
	return 0;
}

int main() {
	cal();
	int n;
	scanf("%d", &n);
	vector<int> first, second;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (i == 0) first.push_back(tmp);
		else {
			if (first[0] % 2 == tmp % 2) first.push_back(tmp);
			else second.push_back(tmp);
		}
	}
	S = 0;
	E = first.size() + second.size() + 1;
	vector<int> join;
	for (int j = 0; j < second.size(); j++) {
		if (prime[first[0] + second[j]]) {
			join.push_back(j);
		}
	}
	vector<int> a;
	for (int k = 0; k < join.size(); k++) {
		for (int i = 0; i < 100; i++) {
			graph[i].clear();
			level[i] = 0;
			for (int j = 0; j < 100; j++) {
				c[i][j] = 0;
				f[i][j] = 0;
			}

		}

		for (int i = 1; i <= first.size(); i++) {
			c[S][i] = 1;
			graph[S].push_back(i);
		}

		for (int i = second.size() + 1; i < E; i++) {
			c[i][E] = 1;
			graph[i].push_back(E);
		}
		for (int i = 1; i < first.size(); i++) {
			for (int j = 0; j < second.size(); j++) {
				if (j == join[k])
					continue;
				if (prime[first[i] + second[j]]) {
					//cout << "connect" << first[i] << "and" << second[j] << endl;
					c[i][j + first.size() + 1] = 1;
					graph[i].push_back(j + first.size() + 1);
					graph[j + first.size() + 1].push_back(i);
				}
			}
		}

		int answer = 0;
		while (bfs()) {
			for (int i = 0; i < 100; i++) work[i] = 0;
			while (1) {
				int flow = dfs(S, 100000);
				if (flow == 0) break;
				answer += flow;
			}
		}
		if (answer == n / 2 - 1) {
			a.push_back(second[join[k]]);
		}
	}
	sort(a.begin(), a.end());
	if (a.size()) {
		for (int i = 0; i < a.size(); i++) printf("%d ", a[i]);
	}
	else {
		printf("-1");
	}
	printf("\n");

}
