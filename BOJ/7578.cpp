#include<iostream>
#include<vector>
#include<map>
using namespace std;
int tree[50000000] = { 0 };
int cal(int node, int start, int end, int left, int right) {
	if (left > end || start > right) return 0;
	else if (left <= start && end <= right) return tree[node];
	else return cal(node * 2, start, (start + end) / 2, left, right)
		+ cal(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void update(int node, int start, int end, int index) {
	if (index < start || end < index) return;
	tree[node] ++;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index);
	}
}
int main() {
	int n, m;
	scanf("%d", &n);
	map<int, int> ma;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		ma[t] = i;
	}
	long long int sum = 0;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		int re = ma[t];
		sum+= cal(1, 0, n - 1, re, n-1);
		update(1, 0, n - 1, re);
	}
	printf("%lld\n", sum);
}