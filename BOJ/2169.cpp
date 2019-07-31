#include<iostream>
#include<algorithm>
#define INF 2000000000
using namespace std;
int arr[1001][1001];
int dp[1001][1001];
int N, M;
int main() {
	scanf("%d %d", &N, &M);
	for(int i=1;i<=N;i++)
		for (int j = 1; j <= M; j++) {
			scanf("%d", &arr[i][j]);
			arr[i][j] += arr[i][j - 1];
		}
	for (int i = 1; i <= M; i++) {
		dp[N][i] = arr[N][M] - arr[N][i - 1];
	}
	for(int i=N-1;i>=1;i--)
		for (int j = 1; j <= M; j++) {
			int ma = -INF;
			for (int k = 1; k <= j; k++) {
				ma = max(ma, arr[i][j] - arr[i][k - 1]+dp[i+1][k]);
			}
			for (int k = j + 1; k <= M; k++) {
				ma = max(ma, arr[i][k] - arr[i][j - 1]+dp[i+1][k]);
			}
			dp[i][j] = ma;
		}
	printf("%d\n", dp[1][1]);
}