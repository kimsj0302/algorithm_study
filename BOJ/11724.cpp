#include<iostream>
#include<vector>

using namespace std;
int a, b;
vector<vector<int> > arr(1001);
bool visited[1001];

void bfs(int node) {
	if (visited[node])
		return;
	visited[node] = true;
	for (int i = 0; i < arr[node].size(); i++) {
		bfs(arr[node][i]);
	}
	return;
}
int main() {
	scanf("%d %d", &a, &b);
	for (int i = 0; i <= a; i++)
		visited[i] = false;
	for (int i = 0; i < b; i++) {
		int q, w;
		scanf("%d%d", &q, &w);
		arr[q].push_back(w);
		arr[w].push_back(q);
	}
	int answer = 0;
	for (int i = 1; i <= a; i++) {
		if (visited[i] == false) {
			answer++;
			bfs(i);
		}
	}
	printf("%d\n", answer);
}