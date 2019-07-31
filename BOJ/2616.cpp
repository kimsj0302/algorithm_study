#include<iostream>
#include<algorithm>
using namespace std;
int dp[4][50001];
int arr[50001];
int n;
int can;
int cal(int cart, int st) {
	if (cart == 0 || st+can-1>n)
		return 0;
	if (dp[cart][st] != 0)
		return dp[cart][st];
	return dp[cart][st] = max(cal(cart, st + 1), arr[st + can - 1] - arr[st - 1] + cal(cart - 1, st + can));
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr[i] = arr[i - 1] + tmp;
	}
	scanf("%d", &can);
	printf("%d\n", cal(3, 1));
}