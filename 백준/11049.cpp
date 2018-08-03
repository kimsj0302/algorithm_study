#include<iostream>
#include<algorithm>
#define INF 2147483647
using namespace std;
int dp[511][511];
int arr[511];
int num;
int cal(int st, int nd) {
	if (st + 1 == nd) {
		return dp[st][nd]=arr[st] * arr[nd] * arr[nd + 1];
	}
	if (st == nd)
		return 0;
	if (dp[st][nd] != INF)
		return dp[st][nd];
	for (int i = 0; st + i < nd; i++) {
		dp[st][nd] = min(dp[st][nd], cal(st + i + 1, nd) + cal(st, st + i) + arr[st + i + 1] * arr[st] * arr[nd + 1]);
	}
	return dp[st][nd];

}
int main() {
		scanf("%d", &num);
		for (int j = 1; j <= num; j++) {
			scanf("%d %d", &arr[j],&arr[j+1]);
		}
		for (int i = 1; i <= num + 1; i++)
			for (int j = 1; j <= num + 1; j++)
				dp[i][j] = INF;
		printf("%d\n", cal(1,num));
	
}