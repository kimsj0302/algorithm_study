#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int num_goods, weight;
		scanf("%d %d", &num_goods, &weight);
		vector<vector<int>> DP(weight+10, vector<int> (num_goods+10, 0));
		vector<int> w_item;
		w_item.push_back(0);

		vector<int> cost;
		cost.push_back(0);
		for (int j = 0; j < num_goods; j++) {
			int tmp;
			scanf("%d", &tmp);
			w_item.push_back(tmp);
		}
		for (int j = 0; j < num_goods; j++) {
			int tmp;
			scanf("%d", &tmp);
			cost.push_back(tmp);
		}
		for (int j = 1; j <= num_goods; j++) {
			for (int k = 1; k <= weight; k++) {
				if (w_item[j] > k)
					DP[k][j] = DP[k][j - 1];
				else {
					DP[k][j] = max(DP[k - w_item[j]][j - 1] + cost[j], DP[k][j - 1]);
				}
			}
		}
		printf("%d\n", DP[weight][num_goods]);
	}
}