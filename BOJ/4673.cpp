#include<iostream>
#include<algorithm>
using namespace std;

int d(int n) {
	int s = n;
	while (n) {
		s += n % 10;
		n /= 10;
	}
	return s;
}

bool isSelf(int n) {
	for (int i = 1; i < n; i++) {
		if (d(i) == n) return false;
	}
	return true;
}
int main() {
	for (int i = 1; i < 10000; i++) {
		if (isSelf(i)) cout << i << endl;
	}
}