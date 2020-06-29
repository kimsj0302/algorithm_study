#include<iostream>
#include<vector>
#include<algorithm>
#define MOD 1000000009
using namespace std;

vector<string> vec;
long long int dp[1000010] = { 0, };
int main() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	int n;
	cin >> n;
	for (int i = 4; i < 1000001; i++) {
		dp[i] = ((dp[i - 1] + dp[i - 2])% MOD + dp[i - 3])%MOD;
	}
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		cout << dp[k] << endl;

	}
}