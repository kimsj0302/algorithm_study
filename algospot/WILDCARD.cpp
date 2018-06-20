#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int dp[101][101];
string W, S;
bool match(int _w,int _s) {
	if (dp[_w][_s] != -1) return dp[_w][_s];
	while (_s < S.size() && _w < W.size() && (W[_w] == '?' || W[_w] == S[_s])) {
		_w++; _s++;
	}
	if (_w == W.size())
		return dp[_w][_s]=(_s==S.size());
	if (W[_w] == '*') {
		for (int i = 0; i + _s <= S.size(); i++) {
			if (match(_w+1, _s + i))
				return dp[_w][_s]=1;
		}
	}
	return dp[_w][_s]=0;
}

int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		vector<string> arr;
		cin >> W;
		int num2;
		cin >> num2;
		getchar();
		for (int i = 0; i < num2; i++) {
			cin >> S;
			for (int i = 0; i < 100; i++) {
				for (int j = 0; j < 100; j++) {
					dp[i][j] = -1;
				}
			}
			if (match(0, 0))
				arr.push_back(S);
		}
		sort(arr.begin(), arr.end());
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << endl;
		}
	}
}