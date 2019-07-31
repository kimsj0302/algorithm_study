#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int V, E;
vector<vector<int> > arr(100005);
int visit[100005];
vector<pair<int, int>> cut;
int dfs(int here, int parent,int num) {
	visit[here] = num;
	int min = num;
	for (int i = 0; i < arr[here].size(); i++) {
		int next = arr[here][i];
		if (next == parent)
			continue;
		if (visit[next]) {
			if (min > visit[next])
				min = visit[next];
		}
		else {
			int search = dfs(next, here, num + 1);
			if (search > visit[here]) {
				if(here<next)
					cut.push_back(make_pair(here, next));
				else
					cut.push_back(make_pair(next, here));
			}
			if (min > search)
				min = search;
		}
	}
	return min;
}
int main() {
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (int i = 1; i <= V; i++) {
		if (visit[i] == 0)
			dfs(i, 0, 1);
	}
	sort(cut.begin(), cut.end());
	printf("%d\n", cut.size());
	for (int i = 0; i < cut.size(); i++) {
		printf("%d %d\n", cut[i].first, cut[i].second);
	}
}