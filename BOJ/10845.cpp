#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void) {
	queue<int> st;
	string command;
	int num;
	int n;
	cin >> num;
	getline(cin, command);
	for (int i = 0; i < num; i++) {
		getline(cin, command);

		if (command == "pop") {
			if (st.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << st.front() << endl;
				st.pop();
			}
		}
		else if (command == "size")
			cout << st.size() << endl;
		else if (command == "empty")
			cout << st.empty() << endl;
		else if (command == "back") {
			if (st.empty())
				cout << "-1" << endl;
			else
				cout << st.back() << endl;
		}
		else if (command == "front") {
			if (st.empty())
				cout << "-1" << endl;
			else
				cout << st.front() << endl;
		}
		else {
			command = command.substr(4);
			n = atoi(command.c_str());
			st.push(n);
		}
	}
	return 0;
}
