#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	while (true) {
		string a;
		cin >> a;
		if (a == "0") break;
		string b = a;
		reverse(a.begin(), a.end());
		if (a == b) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}