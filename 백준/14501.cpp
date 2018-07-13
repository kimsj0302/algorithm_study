#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<int, int>> list;
int dp[20];
int cal(int day) {
	if (day >= n)
		return 0;
	if (dp[day] != 0)
		return dp[day];
	if (day + list[day].first <= n)
		return dp[day] = max(cal(day + 1), list[day].second + cal(day + list[day].first));
	else
		return dp[day]=cal(day+1);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int st, cost;
		scanf("%d%d", &st, &cost);
		list.push_back(make_pair( st,cost));
	}
	printf("%d\n", cal(0));
}