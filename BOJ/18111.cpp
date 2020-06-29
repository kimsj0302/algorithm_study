#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, m, b;
	cin >> n >> m >> b;
	vector<int> vec;
	int min=300, max=0;
	int sum = 0;
	for (int i = 0; i < n*m; i++) {
		int t;
		cin >> t;
		vec.push_back(t);
		if (t > max) max = t;
		if (t < min) min = t;
		sum += t;
	}
	int ans_t=200000000, ans_h=-1;
	for (int i = max; i >= min; i--) {
		if (i * n * m - sum - b > 0) continue;
		int t = 0;
		for (int j = 0; j < n * m; j++) {
			if (vec[j] > i) t += 2*(vec[j] - i);
			else if (vec[j] < i) t += (i-vec[j]);
		}
		if (t < ans_t) {
			ans_t = t;
			ans_h = i;
		}
	}
	cout << ans_t << " "<< ans_h << endl;
}