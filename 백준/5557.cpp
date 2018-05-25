#include<iostream>
#include<vector>

using namespace std;
long long DP[100][21] = { 0, };
int main() {
	int num;
	scanf("%d", &num);
	int ans;
	for (int i = 0; i < num; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (i == 0) {
			DP[0][tmp] = 1;
		}
		else if (i == num - 1) {
			ans = tmp;
		}
		else {
			for (int j = 0; j < 21; j++) {
				if (DP[i-1][j] != 0) {
					if (j + tmp <= 20) {
						DP[i][j + tmp] += DP[i - 1][j];
					}
					if (j - tmp >= 0) {
						DP[i][j - tmp] += DP[i - 1][j];
					}
				}
			}
		}
	}
	
	printf("%lld\n", DP[num-2][ans]);
}