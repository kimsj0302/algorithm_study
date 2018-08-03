#include<iostream>

using namespace std;

int arr[1011];
long long int tree[4014];

long long int init(int node, int st, int nd) {
	if (st == nd) {
		return tree[node] = arr[st];
	}
	else {
		return tree[node] = init(node * 2, st, (st + nd) / 2) + init(node * 2 + 1, (st + nd) / 2 + 1, nd);
	}
}
long long int sum(int node, int st, int nd, int left, int right) {
	if (left > nd || st > right)
		return 0;
	if (left <= st && nd <= right) {
		return tree[node];
	}
	return sum(node * 2, st, (st + nd) / 2, left, right) + sum(node * 2 + 1, (st + nd) / 2 + 1, nd, left, right);
}
void update(int node, int st, int nd, int ind, long long dif) {
	if (ind<st || ind>nd)
		return;
	tree[node] += dif;
	if (st != nd) {
		update(node * 2, st, (st + nd) / 2, ind, dif);
		update(node * 2 + 1, (st + nd) / 2 + 1, nd, ind, dif);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	int m;
	scanf("%d", &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	init(1, 1, n);
	for (int i = 0; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp == 1) {
			int st, nd;
			scanf("%d %d", &st, &nd);
			printf("%lld\n", sum(1, 1, n, st, nd));
			update(1, 1, n, st, arr[nd] - arr[st]);
			update(1, 1, n, nd, arr[st] - arr[nd]);
			int tmp = arr[st];
			arr[st] = arr[nd];
			arr[nd] = tmp;
		}
		else {
			int q, w, e, r;
			scanf("%d %d %d %d", &q, &w, &e, &r);
			printf("%lld\n", sum(1, 1, n, q, w) - sum(1, 1, n, e, r));
		}
	}
}