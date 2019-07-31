#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int dp[4001][4001];
int main() {
	string a, b;
	cin >> a >> b;
	for(int i=0;i<a.size();i++)
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = 0;
			}
		}
	int ma = 0;
	for(int i=0;i<=a.size();i++){
		for (int j = 0; j <= b.size(); j++)
			ma = max(dp[i][j], ma);
		}
	printf("%d\n", ma);
}