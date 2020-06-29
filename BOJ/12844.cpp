#include<iostream>
#include<vector>
using namespace std;
int tree[5000000] = { 0 };
int lazy[5000000] = { 0 };
vector<long long int> vec;
long long int init(int now, int start, int end) {
	if (start == end)
		return tree[now] = vec[start];
	else return tree[now] = init(now * 2, start, (start + end) / 2)
		^ init(now * 2 + 1, (start + end) / 2 + 1, end);
}
void up_lazy(int node, int start, int end) {
	if (lazy[node] != 0) {
		if((end-start+1)%2)
			tree[node] ^= lazy[node];
		if (start != end) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}
int cal(int node, int start, int end, int left, int right) {
	up_lazy(node, start, end);
	if (left > end || start > right) return 0;
	else if (left <= start && end <= right) return tree[node];
	else return cal(node * 2, start, (start + end) / 2, left, right)
		^ cal(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void update(int node, int start, int end, int left,int right, int diff) {
	up_lazy(node, start, end);
	if (right < start || end < left) return;
	else if (left <= start && end <= right) {
		if ((end - start + 1) % 2)
			tree[node] ^= diff;
		if (start != end) {
			lazy[node * 2] ^= diff;
			lazy[node * 2 + 1] ^= diff;
		}
		return;
	}
	update(node * 2, start, (start + end) / 2, left,right, diff);
	update(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}
int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		vec.push_back(t);
	}
	scanf("%d", &m);
	init(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		int a, b,c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) {
			int d;
			scanf("%d", &d);
			update(1, 0, n - 1, b, c,d);
		}
		else {
			printf("%d\n", cal(1, 0, n - 1, b , c));
		}
	}
}