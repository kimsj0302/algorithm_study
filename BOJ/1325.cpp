#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int number[10001];
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	vector<vector<int>> g(n + 1);
	for (int i = 0; i < m; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		g[e].push_back(s);
	}
	int max=0;
	for (int i = 1; i <= n; i++) {
		vector<int> visit(n+1, 0);
		stack<int> st;
		st.push(i);
		while (!st.empty()) {
			int top = st.top();
			st.pop();
			if (visit[top])
				continue;
			visit[top] = 1;
			number[i]++;
			for (int j = 0; j < g[top].size(); j++) {
				if(!visit[g[top][j]])
					st.push(g[top][j]);
			}
		}
		if(max<number[i])
			max=number[i];
	}
	for (int i = 1; i <= n; i++) {
		if (number[i] == max)
			printf("%d ", i);
	}

}