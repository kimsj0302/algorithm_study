#include<iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int result = a * b;
	int r1 = a * (b % 10);
	b /= 10;
	int r2 = a * (b % 10);
	b /= 10;
	int r3 = a * (b % 10);
	b /= 10;
	cout << r1 << "\n" << r2 << "\n" << r3 << "\n" << result << endl;

}