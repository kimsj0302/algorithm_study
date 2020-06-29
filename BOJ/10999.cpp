#include<iostream>
#include<vector>
using namespace std;
long long int tree[5000000] = { 0 };
long long int lazy[5000000] = { 0 };
vector<long long int> vec;
long long int init(int now, int start, int end) {
	if (start == end)
		return tree[now] = vec[start];
	else return tree[now] = init(now * 2, start, (start + end) / 2)
		+ init(now * 2 + 1, (start + end) / 2 + 1, end);
}
void up_lazy(int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] += (long long int)(end - start + 1) * lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
long long int sum(int node, int start, int end, int left, int right) {
	up_lazy(node, start, end);
	if (left > end || start > right) return 0;
	else if (left <= start && end <= right) return tree[node];
	else return sum(node * 2, start, (start + end) / 2, left, right)
		+ sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void update(int node, int start, int end, int left,int right, long long int diff) {
	up_lazy(node, start, end);
	if (right < start || end < left) return;
	else if (left <= start && end <= right) {
		tree[node] += (long long int)(end - start + 1) * diff;
		if (start != end) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}
	update(node * 2, start, (start + end) / 2, left,right, diff);
	update(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		long long int t;
		scanf("%lld", &t);
		vec.push_back(t);
	}
	init(1, 0, n - 1);
	for (int i = 0; i < m + k; i++) {
		int a, b,c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) {
			long long int d;
			scanf("%lld", &d);
			update(1, 0, n - 1, b - 1, c-1,d);
		}
		else {
			printf("%lld\n", sum(1, 0, n - 1, b - 1, c - 1));
		}
	}
}