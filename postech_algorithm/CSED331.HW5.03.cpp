#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int V, E;


vector<vector<int>> ve;
vector<int> check;
vector<long long> DP(100001,0);
long long cal(int num) {
	for (int i = 0; i < ve[num].size(); i++) {
		if (check[ve[num][i]] == 0) {
			DP[num]=(DP[num]+DP[ve[num][i]]) % 2017231920182101;
			continue;
		}
		long long tmp = cal(ve[num][i]);
		DP[num]=(DP[num]+tmp) % 2017231920182101;

	}
	check[num] = 0;
	return DP[num] % 2017231920182101;
}

int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d", &V, &E);
		ve.clear();
		ve.resize(V);
		check.assign(V, 0);
		for (int i = 0; i < V; i++) {
			DP[i] = 0;
			check[i] = 0;
		}
		for (int i = 0; i < E; i++) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			ve[t1].push_back(t2);
			check[t1] = 1;
		}
		DP[V-1] = 1;
		cal(0);
		printf("%lld\n", DP[0]% 2017231920182101);
	}
}