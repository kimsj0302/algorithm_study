#include<iostream>
#include<vector>
using namespace std;
int tree[500000] = { 0 };
int lazy[500000] = { 0 };
void up_lazy(int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] = (end - start + 1) - tree[node];
		if (start != end) {
			lazy[node * 2] = 1 - lazy[node * 2];
			lazy[node * 2 + 1] = 1 - lazy[node * 2 + 1];
		}
		lazy[node] = 0;
	}
}
int cal(int node, int start, int end, int left, int right) {
	up_lazy(node, start, end);
	if (left > end || start > right) return 0;
	else if (left <= start && end <= right) return tree[node];
	else return cal(node * 2, start, (start + end) / 2, left, right)
		+ cal(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void update(int node, int start, int end, int left,int right) {
	up_lazy(node, start, end);
	if (right < start || end < left) return;
	else if (left <= start && end <= right) {
		tree[node] = (end-start+1)-tree[node];
		if (start != end) {
			lazy[node * 2] = 1- lazy[node * 2];
			lazy[node * 2 + 1] = 1- lazy[node * 2 + 1];
		}
		return;
	}
	update(node * 2, start, (start + end) / 2, left,right);
	update(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int main() {
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b,c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0) {
			update(1, 0, n - 1, b-1, c-1);
		}
		else {
			printf("%d\n", cal(1, 0, n - 1, b-1 , c-1));
		}
	}
}