#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> arr;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	int wait = 0, ans = 0, st = 0, nd = arr.size() - 1;
	while (st <= nd) {
		if (arr[st] < wait) {
			st++;
		}
		else {
			if (wait <= arr[nd]) {
				nd--;
				wait++;
			}
			else {
				nd--;
			}
		}
	}
	printf("%d\n", wait);
}