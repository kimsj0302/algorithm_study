#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int DP[3001][3001] = { 0, };
int main() {
	int A, B, C;
	string a, b;
	cin >> A >> B >> C;
	cin >> a >> b;
	for (int i = 1; i < 3001; i++) {
		DP[0][i] = DP[i][0] = i*B;
	}
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i-1] == b[j-1]) {
				DP[i][j] = DP[i - 1][j - 1]+A;
			}
			else {
				DP[i][j] = max(DP[i - 1][j - 1] + max(2 * B, C),max(DP[i][j-1]+B,DP[i-1][j]+B));
			}
		}
	}

	printf("%d\n", DP[a.size()][b.size()]);
}