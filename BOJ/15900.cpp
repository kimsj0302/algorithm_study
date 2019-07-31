#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<vector<int>> arr(500001);
bool visited[500001];
int sum;

void search(int n,int num) {
	visited[n] = true;
	bool leaf = true;
	for (int i = 0; i < arr[n].size(); i++) {
		if (!visited[arr[n][i]]) {
			leaf = false;
			search(arr[n][i], num + 1);
		}
	}
	if (leaf)
		sum += num;
	return;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (int i = 0; i <= n; i++) visited[i] = false;
	search(1, 0);
	cout << ((sum%2) ?"Yes":"No");
}