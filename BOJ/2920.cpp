#include<iostream>
using namespace std;
int main() {
	int m[8];
	for (int i = 0; i < 8; i++) {
		cin >> m[i];
	}
	bool a = true, d = true;
	for (int i = 1; i <= 8; i++) {
		if (i != m[i - 1]) a = false;
		if (i != 9-m[i - 1]) d = false;
	}
	if (a) cout << "ascending" << endl;
	else if (d) cout << "descending" << endl;
	else cout << "mixed" << endl;
}