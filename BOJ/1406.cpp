#include <algorithm>
#include <iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
	stack <char> left, right;
	string a;
	cin >> a;
	for (int i = 0; i<a.size(); i++) {
		left.push(a[i]);
	}
	int command;
	char b[10];
	char tmp;
	scanf("%d", &command);
	for (int i = 0; i < command; i++) {
		scanf("%s",b);
		if (b[0] == 'L' && left.empty()==0) {
			tmp = left.top();
			left.pop();
			right.push(tmp);
		}
		else if (b[0] == 'D' && right.empty()==0) {
			tmp = right.top();
			right.pop();
			left.push(tmp);
		}
		else if (b[0] == 'B' && left.empty() == 0) {
			left.pop();
		}
		else if(b[0]=='P'){
			getchar();
			char k = getchar();
			left.push(k);
		}
	}
	while (!left.empty()) {
		tmp = left.top();
		left.pop();
		right.push(tmp);
	}
	while (!right.empty()) {
		printf("%c",right.top());
		right.pop();
	}
}
