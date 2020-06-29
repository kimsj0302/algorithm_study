#include<iostream>
using namespace std;
int main() {
	while (true) {
		long long int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;
		
		if (a * a + b * b == c * c || a * a == b * b + c * c || a * a + c * c == b * b) cout << "right" << endl;
		else cout << "wrong" << endl;
	}
}