#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int suffle[101];
	vector<pair<int, int>> arr;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int tmp;
		scanf("%d", &tmp);
		suffle[tmp] = i;
	}
	for (int i = 1; i <= n; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(make_pair(suffle[suffle[suffle[i]]],tmp));
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i].second);
	}
}