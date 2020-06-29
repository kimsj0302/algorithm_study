#include<iostream>
#include<algorithm>
using namespace std;

int arr[100011];
pair<long long int,int> tree[100011*4];
int indexing[100011];
pair<long long int,int> init(int node, int st, int nd) {
	if (st == nd) {
		indexing[st] = node;
		return tree[node] = make_pair(arr[st],st);
	}
	else {
		return tree[node] = min(init(node * 2, st, (st + nd) / 2) , init(node * 2 + 1, (st + nd) / 2 + 1, nd));
	}
}
pair<long long int,int> mi(int node, int st, int nd, int left, int right) {
	if (left > nd || st > right)
		return make_pair(100000001,0);
	if (left <= st && nd <= right) {
		return tree[node];
	}
	return min(mi(node * 2, st, (st + nd) / 2, left, right) , mi(node * 2 + 1, (st + nd) / 2 + 1, nd, left, right));
}
void update(int node, int ind, long long num) {
	
	int here = indexing[ind];
	tree[here] = make_pair(num,ind);
	here /= 2;
	while (here) {
		tree[here] = min(tree[here * 2], tree[here * 2 + 1]);
		here /= 2;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	init(1, 1, n);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp == 2) {
			int st, nd;
			scanf("%d %d", &st, &nd);
			printf("%d\n",mi(1, 1, n, st, nd).second);
		}
		else {
			int a, b;
			scanf("%d %d", &a, &b);
			update(1,  a, b);
		}
	}
}