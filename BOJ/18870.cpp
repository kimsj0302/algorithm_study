#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	map<int, int> ma;
	int n;
	scanf("%d", &n);
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		arr.push_back(t);
	}
	vector<int> original(arr);
	sort(arr.begin(), arr.end());
	int count = 1;
	for (int i = 0; i < n; i++) {
		if (ma[arr[i]] == 0) ma[arr[i]] = count++;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", ma[original[i]]-1);
	}
	printf("\n");
}
