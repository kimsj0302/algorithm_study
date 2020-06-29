#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long int tree[5000000] = { 0 };
vector<long long int> vec;
long long int init(int now, int start,int end) {
	if (start == end)
		return tree[now] = vec[start];
	else return tree[now] = min(init(now * 2, start, (start + end) / 2)
						  , init(now * 2 + 1, (start + end) / 2 + 1, end));
}
long long int find(int node,int start, int end,int left,int right) {
	if (left > end || start > right) return 2147483647;
	else if (left <= start && end <= right) return tree[node];
	else return min(find(node * 2, start, (start + end) / 2, left, right)
			  , find(node * 2+1, (start + end) / 2+1,end, left, right));
}
void update(int node, int start, int end, int index, long long int num) {
	if (index < start || end < index) return;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, num);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, num);
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	}
	else tree[node] = num;

}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n;i++) {
		long long int t;
		scanf("%d", &t);
		vec.push_back(t);
	}
	int m;
	scanf("%d", &m);
	init(1, 0, n-1);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 1) {
			long long int c;
			scanf("%lld", &c);
			update(1, 0, n - 1, b - 1, c);
			vec[b - 1] = c;
		}
		else {
			int c;
			scanf("%d", &c);
			printf("%lld\n", find(1, 0, n - 1, b-1, c-1));
		}
	}
}