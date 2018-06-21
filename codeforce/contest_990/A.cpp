#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}
	int count = 0;
	for (int i = 0; i<n && arr[i] <= m; i++) {
		count++;
	}
	reverse(arr.begin(), arr.end());
	for (int i = 0; i<n && arr[i] <= m; i++) {
		count++;
	}
	printf("%d\n", min(n,count));
}