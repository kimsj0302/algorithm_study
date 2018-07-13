#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int in[1001];
int de[1001];
int main() {
	int n;
	scanf("%d", &n);
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}
	in[0] = 1;
	de[n - 1] = 1;
	for (int i = 1; i < n; i++) {
		in[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				in[i] = max(in[i], in[j] + 1);
			}
		}
	}
	for (int i = n - 2; i >= 0; i--) {
		de[i] = 1;
		for (int j = n - 1; j > i; j--) {
			if (arr[j] < arr[i]) {
				de[i] = max(de[i], de[j] + 1);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, in[i] + de[i]);
	}
	printf("%d\n", max(1,ans-1));
}