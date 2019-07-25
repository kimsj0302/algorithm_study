#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	string tmp;
	getline(cin, tmp);
	bool u = false, c = false, p = false, c_ = false;
	for (int i = 0; i < tmp.size(); i++) {
		if (u && c && p && tmp[i]=='C') {
			c_ = true;
		}
		else if (u && c &&  tmp[i] == 'P') {
			p = true;
		}
		else if (u && tmp[i] == 'C') {
			c = true;
		}
		else if (tmp[i] == 'U') {
			u = true;
		}
	}
	cout << ((u && c && p && c_) ? "I love UCPC" : "I hate UCPC");
}