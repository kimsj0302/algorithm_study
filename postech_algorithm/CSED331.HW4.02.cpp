#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
	int from, to;
	int cost;
};
bool operator<(node N1, node N2) {
	return N1.cost < N2.cost;
}



int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int V, E;
		scanf("%d %d", &V, &E);
		vector<node> list;
		vector<int> disjoint(V, 0);
		int answer = 0;
		for (int j = 0; j < V; j++) {
			disjoint[j] = j;
		}
		for (int j = 0; j < E; j++) {
			int f, t, c;
			scanf("%d %d %d", &f, &t, &c);
			node tmp = { f,t,c };
			list.push_back(tmp);
		}
		sort(list.begin(), list.end());
		for (int j = 0; j < E; j++) {
			int from =  list[j].from;
			int to = list[j].to;
			
			while (from != disjoint[from]) {
				from = disjoint[from];
			}
			while (to != disjoint[to]) {
				to = disjoint[to];
			}
			if (to != from) {
				int tmp1 = to < from ? from : to;
				int tmp2 = to + from - tmp1;
				for (int k = 0; k < disjoint.size(); k++) {
					if (disjoint[k] == tmp2)
						disjoint[k] = tmp1;
				}
				answer += list[j].cost;
			}
		}
		printf("%d\n", answer);
	}
}