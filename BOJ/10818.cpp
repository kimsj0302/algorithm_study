#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int min = 1000000;
	int max = -1000000;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (t < min) min = t;
		if (t > max) max = t;
	}
	cout << min << " "<<max << endl;
}