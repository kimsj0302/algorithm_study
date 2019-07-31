#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	vector<pair<int, int>> list;
	pair<int, int> tmp;
	int latest = 0;
	int count = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp.second >> tmp.first;
		list.push_back(tmp);
	}

	sort(list.begin(), list.end());

	int end_time = 0;

	for (int i = 0; i < n; i++) {
		if (end_time == list[i].first && end_time == list[i].second) {
			count++;
			continue;
		}
		if (list[i].second >= end_time) {
			end_time = list[i].first;
			count++;
		}
	}
	cout << count;
	return 0;
}