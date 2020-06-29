#include<iostream>
using namespace std;
int check(int n) {
	while (n != 0) {
		if (n % 1000 == 666) return 1;
		n /= 10;
	}
	return 0;
}
int main() {
	int c = 0;
	int n;
	cin >> n;
	int i;
	for (i = 666;; i++) {
		c += check(i);
		if (n == c) break;
	}
	cout << i << endl;
}