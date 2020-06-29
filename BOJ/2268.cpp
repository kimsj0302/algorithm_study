#include<iostream>
#include<vector>
using namespace std;
long long int tree[5000000] = { 0 };
vector<long long int> vec;
long long int init(int now, int start, int end) {
	if (start == end)
		return tree[now] = vec[start];
	else return tree[now] = init(now * 2, start, (start + end) / 2)
		+ init(now * 2 + 1, (start + end) / 2 + 1, end);
}
long long int sum(int node, int start, int end, int left, int right) {
	if (left > end || start > right) return 0;
	else if (left <= start && end <= right) return tree[node];
	else return sum(node * 2, start, (start + end) / 2, left, right)
		+ sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void update(int node, int start, int end, int index, long long int diff) {
	if (index < start || end < index) return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		vec.push_back(0);
	}
	init(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a == 1) {
			long long int c;
			scanf("%lld", &c);
			update(1, 0, n - 1, b - 1, c - vec[b - 1]);
			vec[b - 1] = c;
		}
		else {
			int c;
			scanf("%d", &c);
			if (b > c) {
				int tmp;
				tmp = b;
				b = c;
				c = tmp;
			}
			printf("%lld\n", sum(1, 0, n - 1, b - 1, c - 1));
		}
	}
}