#include<iostream>
using namespace std;
int main() {
	int mod[42] = { 0, };
	for (int i = 0; i < 10; i++) {
		int t;
		cin >> t;
		mod[t % 42] = 1;
	}
	int sum = 0;
	for (int i = 0; i < 42; i++) {
		sum += mod[i];
	}
	cout << sum << endl;
}