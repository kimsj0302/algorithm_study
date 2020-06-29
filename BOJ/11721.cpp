#include<iostream>

using namespace std;

int main() {
	string a;
	cin >> a;
	for (int i = 1; i <= a.size(); i++) {
		cout << a[i-1];
		if (i % 10 == 0) {
			cout << "\n";
		}
	}
	
}