#include<iostream>
using namespace std;
int main() {
	int mod[10] = { 0, };
	long long int mul=1;
	int t;
	cin >> t;
	mul *= t;
	cin >> t;
	mul *= t;
	cin >> t;
	mul *= t;
	while (mul != 0) {
		mod[mul % 10]++;
		mul /= 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << mod[i] << endl;
	}

}