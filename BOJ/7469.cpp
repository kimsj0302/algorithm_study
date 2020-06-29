#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
vector<int> tree[500000];
vector<int> vec;

vector<int> init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = vector<int>{ vec[start] };
	}
	else {
		vector<int> a = init(node * 2, start, (start + end) / 2);
		vector<int> b = init(node * 2 + 1, (start + end) / 2 + 1, end);
		a.insert(a.begin(), b.begin(), b.end());
		sort(a.begin(), a.end());
		return tree[node]=a;
	}
}

int cal(int node, int start, int end, int left,int right, int num) {
	if (left > end || start > right) return 0;
	else if (left <= start && end <= right) return upper_bound(tree[node].begin(), tree[node].end(),num)-tree[node].begin();
	else return cal(node * 2, start, (start + end) / 2, left, right,num)
		+ cal(node * 2 + 1, (start + end) / 2 + 1, end, left, right,num);
}
int main() {
	int n, m;
	scanf("%d %d", &n,&m);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		vec.push_back(t);
	}
	init(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int s = -1e9, e = 1e9;
		while (s <= e) {
			int mid = (s + e) / 2;
			if (cal(1, 0, n - 1, a - 1, b - 1, mid) < c) s = mid + 1;
			else e = mid - 1;
		}
		printf("%d\n", s);
	}
}