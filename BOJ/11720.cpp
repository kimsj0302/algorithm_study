#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	string a;
	cin >> a;
	int sum = 0;
	for (int i = 0; i < a.size(); i++) {
		sum += a[i] - '0';
	}
	
	cout << sum;
}