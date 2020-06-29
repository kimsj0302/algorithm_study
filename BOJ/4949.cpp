#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
	while (true) {
		string str;
		getline(cin,str);
		if (str == ".") break;
		stack<char> sta;
		bool check = true;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(' || str[i] == '[') sta.push(str[i]);
			if (str[i] == ')') {
				if (sta.empty() || sta.top() != '(') {
					cout << "no" << endl;
					check = false;
					break;
				}
				sta.pop();
			}
			if (str[i] == ']') {
				if (sta.empty() || sta.top() != '[') {
					cout << "no" << endl;
					check = false;
					break;
				}
				sta.pop();
			}
		}
		if (check) {
			if (sta.empty()) {
				cout << "yes" << endl;
			}
			else {
				cout << "no" << endl;
			}
		}

	}
}