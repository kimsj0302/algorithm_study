#include<iostream>
using namespace std;
int cal(int n) {
	int sum = n;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
int main() {
	
	int n; int i;
	cin >> n;
	for (i = 0; i <= 1000000; i++) {
		if (n == cal(i)) {
			cout << i << endl;
			break;
		}
	}
	if (i == 1000001) cout << 0 << endl;
}