#include<iostream>
#include<algorithm>
using namespace std;
int dp[21][21][21];
int arr[21];
int n;
int k;
int cal(int ind, int open1, int open2) {
	if (ind > k)
		return 0;
	if (arr[ind] == open1 || arr[ind] == open2)
		return dp[ind][open1][open2]=cal(ind + 1, open1, open2);
	if (dp[ind][open1][open2] != -1)
		return dp[ind][open1][open2];
	int dis1 = open1 - arr[ind];
	int mi;
	if (dis1 < 0) 
		dis1 = -dis1;
	if (arr[ind] > open2)
		mi = dis1 + cal(ind + 1, open2, arr[ind]);
	else
		mi = dis1 + cal(ind + 1, arr[ind], open2);
	int dis2 = open2 - arr[ind];
	if (dis2 < 0)
		dis2 = -dis2;
	if (arr[ind] > open1)
		mi = min(mi,dis2 + cal(ind + 1, open1, arr[ind]));
	else
		mi = min(mi,dis2 + cal(ind + 1, arr[ind], open1));
	return dp[ind][open1][open2] = mi;

}
int main() {
	scanf("%d", &n);
	int a, b;
	scanf("%d %d", &a, &b);
	scanf("%d", &k);
	for (int i = 1; i <= k; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 21; j++)
			for (int k = 0; k < 21; k++)
				dp[i][j][k] = -1;
	
	printf("%d\n", cal(1, a, b));
	
}