#include<iostream>
using namespace std;
int main() {
	long long int r = 31, M = 1234567891;
	long long int n;
	cin >> n;
	long long int ans = 0;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		long long int t = (int)(c - 'a')+1;
		for (int j = 0; j < i; j++) {
			t = (t * r) % M;
		}
		ans = (t+ans) % M;
	}
	cout << ans << endl;
}