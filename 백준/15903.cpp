#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


int main() {
	long long int n, m;
	cin >> n >> m;
	priority_queue<long long int> que;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		que.push(-1*tmp);
	}
	for (int i = 0; i < m; i++) {
		long long int a, b;
		a = que.top();
		que.pop();
		b = que.top();
		que.pop();
		que.push(a + b);
		que.push(a + b);
	}
	long long int sum = 0;
	while (!que.empty()) {
		sum += que.top();
		que.pop();
	}
	cout << -1*sum << endl;
}