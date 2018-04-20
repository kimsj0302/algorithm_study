#include <algorithm>
#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(void) {
	deque <int> a;
	string command;
	int num;
	int n;
	cin >> num;
	getline(cin, command);
	for (int i = 0; i < num; i++) {
		getline(cin, command);

		if (command == "pop_front") {
			if (a.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << a.front() << endl;
				a.pop_front();
			}
		}
		else if (command == "pop_back") {
			if (a.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << a.back() << endl;
				a.pop_back();
			}
		}
		else if (command == "empty")
			cout << a.empty() << endl;
		else if (command == "size")
			cout << a.size() << endl;
		else if (command == "front") {
			if (a.empty())
				cout << "-1" << endl;
			else
				cout << a.front() << endl;
		}
		else if (command == "back") {
			if (a.empty())
				cout << "-1" << endl;
			else
				cout << a.back() << endl;
		}
		else if (command.substr(0,9) == "push_back") {
			n = stoi(command.substr(10, command.length()));
			a.push_back(n);
		}
		else if (command.substr(0, 10) == "push_front") {
			n = stoi(command.substr(11, command.length()));
			a.push_front(n);
		}
	}
	return 0;
}
