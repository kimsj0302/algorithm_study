#include<iostream>
#include<vector>

using namespace std;
int DP[1001] = { 0, };
int main() {
	int num;
	scanf("%d", &num);
	int ans;
	vector<int> arr;
	for (int i = 0; i < num; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp);
		if (i == 0)
			continue;
		if (i == 1) {
			if (arr[1] - arr[0] >= 0) 
				DP[1] = arr[1] - arr[0];
			else
				DP[1] = arr[0] - arr[1];
			continue;
		}
		int mi, ma;
		mi = ma = tmp;
		DP[i] = DP[i - 1];
		for (int j = i-1; j > 0; j--) {
			if (arr[j] > ma)
				ma = arr[j];
			if (arr[j] < mi)
				mi = arr[j];
			if (DP[j - 1] + (ma - mi) > DP[i]) {
				DP[i] = DP[j - 1] + (ma - mi);
			}
		}
	}
	printf("%d\n", DP[num - 1]);
}