#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> arr;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		arr.push_back(make_pair(a, i));
	}
	sort(arr.begin(), arr.end());
	int ans = -1000000;
	for (int i = 0; i < n; i++) {
		if (ans < arr[i].second - i)
			ans = arr[i].second - i;
	}
	printf("%d\n", ans + 1);
}