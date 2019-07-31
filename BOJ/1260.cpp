#include <algorithm>
#include <iostream>
#include <cstring>
#include<string.h>
#include<vector>
#include <stdio.h>
#include <time.h>

#include<stack>
#include<queue>

using namespace std;
int main() {
	vector <vector<int>> V(1001);
	int n, m;
	int start_V;
	int i;
	int a, b;
	scanf("%d %d %d", &n, &m, &start_V);

	
	for (i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		V[a].push_back(b);
		V[b].push_back(a);
	}
	for(i=1;i<=n;i++)
		sort(V[i].begin(), V[i].end());
	for (i = 1; i <= n; i++) {
		V[i].push_back(0);
	}
	
	stack <int> st;
	int point;
	int DFS[1001] = { 0, };
	int BFS[1001] = { 0, };
	st.push(start_V);
	printf("%d ", start_V);
	DFS[start_V] = 1;
	point = start_V;
	for (i = 0;!st.empty(); i++) {
		//printf("[%d] ", st.top());
		//printf("-%d-", st.size());
		if (V[st.top()][i] == 0) {
			st.pop();
			i = -1;
			continue;
		}
		if (DFS[V[st.top()][i]] == 0) {
			point = V[st.top()][i];
			st.push(point);
			printf("%d ", point);
			DFS[point] = 1;
			i = -1;
			continue;
		}
	}
	queue <int> que;

	que.push(start_V);
	printf("\n%d ", start_V);
	BFS[start_V] = 1;
	point = start_V;
	for (i = 0; !que.empty(); i++) {
		//printf("[%d] ", st.top());
		if (V[que.front()][i] == 0) {
			que.pop();
			i = -1;
			continue;
		}
		if (BFS[V[que.front()][i]] == 0) {
			point = V[que.front()][i];
			que.push(point);
			printf("%d ", point);
			BFS[point] = 1;
			i = -1;
			continue;
		}
	}
}