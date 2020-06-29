#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

bool com1(string a, string b) {
	if (a.size() != b.size())
		return a.size() < b.size();
	int asum = 0, bsum = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9')
			asum += a[i] - '0';
	}
	for (int i = 0; i < b.size(); i++) {
		if (b[i] >= '0' && b[i] <= '9')
			bsum += b[i] - '0';
	}
	if (asum != bsum) {
		return asum < bsum;
	}
	else {
		return a < b;
	}
}

int main() {
	vector<string> arr;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end(), com1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
}