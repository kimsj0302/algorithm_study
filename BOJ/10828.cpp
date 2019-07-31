#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	stack<int> st;
	string command;
	int num;
	int n;
	cin >> num;
	getline(cin, command);
	for (int i = 0; i < num; i++) {
		getline(cin, command);

		if (command == "pop") {
			if (st.empty()) {
				cout << "-1"<<endl;
			}
			else {
				cout << st.top()<<endl;
				st.pop();
			}
		}
		else if (command == "size")
			cout << st.size()<<endl;
		else if (command == "empty")
			cout << st.empty()<<endl;
		else if (command == "top") {
			if (st.empty()) 
				cout << "-1"<<endl;
			else 
				cout << st.top()<<endl;	
		}
		else {
			command = command.substr(4);
			n = atoi(command.c_str());
			st.push(n);
		}
	}
	return 0;
}
