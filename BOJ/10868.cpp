#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int tree[500000] = { 0 };
vector<long long int> vec;
int init(int now, int start,int end) {
	if (start == end)
		return tree[now] = vec[start];
	else return tree[now] = min(init(now * 2, start, (start + end) / 2)
						       , init(now * 2 + 1, (start + end) / 2 + 1, end));
}
int find(int node,int start, int end,int left,int right) {
	if (left > end || start > right) return 2147483647;
	else if (left <= start && end <= right) return tree[node];
	else return min(find(node * 2, start, (start + end) / 2, left, right) 
				  , find(node * 2+1, (start + end) / 2+1,end, left, right));
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n;i++) {
		long long int t;
		scanf("%d", &t);
		vec.push_back(t);
	}
	init(1, 0, n-1);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n",find(1, 0, n - 1, a - 1, b - 1));
	}
}