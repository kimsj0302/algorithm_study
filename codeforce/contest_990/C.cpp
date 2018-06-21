#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;


int main() {
	int num, remove;
	string a;
	scanf("%d %d", &num, &remove);
	vector<pair<char, int>> arr;
	map<int, bool> ma;
	cin >> a;
	for (int i = 0; i < num; i++) {
		arr.push_back(make_pair(a[i], i));
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < remove; i++) {
		ma[arr[i].second] = 1;
	}
	for (int i = 0; i < num; i++) {
		if (ma[i] != 0)
			continue;
		printf("%c", a[i]);
	}
}