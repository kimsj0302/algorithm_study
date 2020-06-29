#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
	int k;
	cin >> k;
	stack<int> sta;
	for (int i = 0; i < k; i++) {
		int t;
		cin >> t;
		if (t == 0) sta.pop();
		else sta.push(t);
	}
	int sum=0;
	while (!sta.empty()) {
		sum += sta.top();
		sta.pop();
	}
	cout << sum << endl;
}