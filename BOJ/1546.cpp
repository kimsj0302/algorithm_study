#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	float s[1001];
	int max = 0;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		s[i] = (float)t;
		if (t > max) max = t;
	}
	for (int i = 0; i < n; i++) {
		s[i] = s[i] / max * 100;
	}
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += s[i];
	}
	cout << sum / (float)n << endl;
}