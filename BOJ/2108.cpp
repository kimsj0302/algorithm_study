#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

bool comp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}
int main() {
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		arr.push_back(t);
	}
	sort(arr.begin(), arr.end());
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (arr[i] / (double)n);
	}
	if(sum<0)
		cout << (int)(sum-0.5) << endl;
	else
		cout << (int)(sum + 0.5) << endl;
	cout << arr[n / 2] << endl;
	map<int, int> ma;
	for (int i = 0; i < arr.size(); i++) {
		ma[arr[i]]++;
	}
	vector<pair<int, int> > vec(ma.begin(), ma.end());
	sort(vec.begin(), vec.end(), comp);
	//for (int i = 0; i < vec.size(); i++) cout << vec[i].first << " " << vec[i].second << endl;
	if(vec.size()>1 && vec[0].second == vec[1].second)
		cout << vec[1].first << endl;
	else
		cout << vec[0].first << endl;

	cout << arr[n - 1] - arr[0] << endl;
}