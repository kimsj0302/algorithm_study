#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dp[101][1001];
vector<int> arr;
int N, S, M;
int cal(int song, int now) {
	if (now<0 || now>M)
		return -1;
	if (song == N)
		return now;
	if (dp[song][now] != -2)
		return dp[song][now];
	return dp[song][now] = max(cal(song + 1, now + arr[song]), cal(song + 1, now - arr[song]));
}

int main() {
	scanf("%d %d %d", &N, &S, &M);
	for (int i = 0; i < N; i++) {
		int tm;
		scanf("%d", &tm);
		arr.push_back(tm);
	}
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 1001; j++)
			dp[i][j] = -2;
	printf("%d\n", cal(0, S));
}