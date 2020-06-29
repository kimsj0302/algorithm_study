#include<iostream>
#include<vector>
using namespace std;
long long int tree[5000000] = { 0 };
vector<long long int> vec;
long long int init(int now, int start,int end) {
	if (start == end)
		return tree[now] = vec[start];
	else return tree[now] = init(now * 2, start, (start + end) / 2)
						  + init(now * 2 + 1, (start + end) / 2 + 1, end);
}
long long int sum(int node,int start, int end,int left,int right) {
	if (left > end || start > right) return 0;
	else if (left <= start && end <= right) return tree[node];
	else return sum(node * 2, start, (start + end) / 2, left, right) 
			  + sum(node * 2+1, (start + end) / 2+1,end, left, right);
}
void update(int node, int start, int end, int index, long long int diff) {
	if (index < start || end < index) return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2+1, (start + end) / 2+1,end, index, diff);
	}
}
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n;i++) {
		long long int t;
		cin >> t;
		vec.push_back(t);
	}
	init(1, 0, n-1);
	for (int i = 0; i < m + k; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			long long int c;
			cin >> c;
			update(1, 0, n - 1, b-1, c - vec[b-1]);
			vec[b - 1] = c;
		}
		else {
			int c;
			cin >> c;
			cout << sum(1, 0, n - 1, b-1, c-1)<<endl;
		}
	}
}