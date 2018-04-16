#include<iostream>
#include<queue>
using namespace std;

struct node {
	int weight;
	vector<int> con;
};

int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int m, n;
		vector<node> list;
		scanf("%d %d", &m, &n);
		for (int j = 0; j < m; j++) {
			node tmp;
			tmp.weight = 1000000;
			list.push_back(tmp);
		}
		for (int j = 0; j < n; j++) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			list[t1].con.push_back(t2);
		}
		list[0].weight = 0;
		queue<node> que;
		que.push(list[0]);
		while (!que.empty()) {
			node now = que.front();
			int min = now.weight + 1;
			que.pop();
			for (int j = 0; j < now.con.size(); j++) {
				if (list[now.con[j]].weight == 1000000) {
					list[now.con[j]].weight = min;
					que.push(list[now.con[j]]);
				}
				else if(list[now.con[j]].weight > min)
					list[now.con[j]].weight = min;
			}
		}
		if (list[m - 1].weight == 1000000)
			printf("-1\n");
		else
			printf("%d\n", list[m - 1].weight);
	}
}