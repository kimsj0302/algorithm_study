#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int sum = 2;
	int t = 1;
	int inter = 6;
	while (true) {
		if (n < sum) { cout << t << endl; break; }
		t++;
		sum += inter;
		inter += 6;
	}
}