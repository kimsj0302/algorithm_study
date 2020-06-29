#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int tree1[500000] = { 0 };
int tree2[500000] = { 0 };
vector<long long int> vec;
int init1(int now, int start,int end) {
	if (start == end)
		return tree1[now] = vec[start];
	else return tree1[now] = min(init1(now * 2, start, (start + end) / 2)
						       , init1(now * 2 + 1, (start + end) / 2 + 1, end));
}
int init2(int now, int start, int end) {
	if (start == end)
		return tree2[now] = vec[start];
	else return tree2[now] = max(init2(now * 2, start, (start + end) / 2)
		, init2(now * 2 + 1, (start + end) / 2 + 1, end));
}
int find1(int node,int start, int end,int left,int right) {
	if (left > end || start > right) return 2147483647;
	else if (left <= start && end <= right) return tree1[node];
	else return min(find1(node * 2, start, (start + end) / 2, left, right) 
				  , find1(node * 2+1, (start + end) / 2+1,end, left, right));
}
int find2(int node, int start, int end, int left, int right) {
	if (left > end || start > right) return 0;
	else if (left <= start && end <= right) return tree2[node];
	else return max(find2(node * 2, start, (start + end) / 2, left, right)
		, find2(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n;i++) {
		long long int t;
		scanf("%d", &t);
		vec.push_back(t);
	}
	init1(1, 0, n-1);
	init2(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d %d\n",find1(1, 0, n - 1, a - 1, b - 1), find2(1, 0, n - 1, a - 1, b - 1));
	}
}