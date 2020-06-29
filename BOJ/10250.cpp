#include<iostream>
using namespace std;
int main() {
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int h, w, n;
		cin >> h >> w >> n;
		int ans = (n-1)/h + 1;
		ans += (n % h) * 100;
		if (n % h == 0) ans += h * 100;
		cout << ans << endl;
	}

}