#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


vector<vector<int> > cal(int m, vector<int> arr) {
	if (m == 0 || arr.size()<m) {
		return vector < vector<int>>();
	}
	vector<vector<int>> result;
	for (int i = 0; i < arr.size(); i++) {
		vector<int> c;
		for (int j = 0; j < arr.size(); j++) {
			if (i != j)
				c.push_back(arr[j]);
		}
		vector<vector<int> > r = cal(m - 1, c);
		for (int j = 0; j < r.size(); j++) {
			r[j].push_back(arr[i]);
			result.push_back(r[j]);
		}
		if (r.size() == 0) {
			vector<int> a;
			a.push_back(arr[i]);
			result.push_back(a);
		}
	}
	return result;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		arr.push_back(t);
	}
	vector<vector<int>> result  = cal(m, arr);
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
}