#include <cstdio>
#include <cstring>
#include <climits>
int n, m, A[100], B[100], dp[101][101];
int max(int a, int b) { return a>b ? a : b; }
int solve(int Ai, int Bi) {
	int &ret = dp[Ai + 1][Bi + 1];
	if (ret != -1) return ret;
	ret = 0;
	int pA, pB, pivot;
	pA = Ai == -1 ? INT_MIN : A[Ai];
	pB = Bi == -1 ? INT_MIN : B[Bi];
	pivot = max(pA, pB);
	for (int i = Ai + 1; i<n; i++)
		if (pivot < A[i])
			ret = max(ret, solve(i, Bi) + 1);
	for (int i = Bi + 1; i<m; i++)
		if (pivot < B[i])
			ret = max(ret, solve(Ai, i) + 1);
	return ret;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int i;
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		memset(dp, -1, sizeof(int) * 101 * 101);
		scanf("%d%d", &n, &m);
		for (i = 0; i<n; i++)
			scanf("%d", &A[i]);
		for (i = 0; i<m; i++)
			scanf("%d", &B[i]);
		printf("%d\n", solve(-1, -1));
	}
}