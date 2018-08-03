#include<iostream>
#include<string>
using namespace std;
int dp[2][21][101];
string roll, up, down;
int cal(int place, int suc, int now) {
	if (suc == roll.size()-1) {
		return 1;
	}
	if (dp[place][suc][now] != 0)
		return dp[place][suc][now];
	if (place == 0) {
		int sum = 0;
		for (int i = now+1; i < down.size(); i++) {
			if (down[i] == roll[suc + 1]) {
				sum += cal(1, suc + 1, i);
			}
		}
		return dp[place][suc][now] = sum;
	}
	else {
		int sum = 0;
		for (int i = now + 1; i < up.size(); i++) {
			if (up[i] == roll[suc + 1]) {
				sum += cal(0, suc + 1, i);
			}
		}
		return dp[place][suc][now] = sum;
	}
}
int main() {
	cin >> roll>> up>> down;
	
	printf("%d\n", cal(0, -1, -1) + cal(1, -1, -1));
}