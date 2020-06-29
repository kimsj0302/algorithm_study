#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long int tree[5000000] = { 0 };
vector<long long int> vec;
#define MOD 1000000007
long long int init(int now, int start,int end) {
	if (start == end)
		return tree[now] = vec[start];
	else return tree[now] = (init(now * 2, start, (start + end) / 2)
						  * init(now * 2 + 1, (start + end) / 2 + 1, end))%MOD;
}
long long int find(int node,int start, int end,int left,int right) {
	if (left > end || start > right) return 1;
	else if (left <= start && end <= right) return tree[node];
	else return (find(node * 2, start, (start + end) / 2, left, right)
			  * find(node * 2+1, (start + end) / 2+1,end, left, right))%MOD;
}
void update(int node, int start, int end, int index, long long int div, long long int mul) {
	if (index < start || end < index) return;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, div, mul);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, div, mul);
		tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
	}
	else tree[node] = mul;

}
int main() {
	int n;
	scanf("%d", &n);
	int m;
	scanf("%d", &m);
	int k;
	scanf("%d", &k);
	for (int i = 0; i < n;i++) {
		long long int t;
		scanf("%lld", &t);
		vec.push_back(t);
	}
	init(1, 0, n-1);
	for (int i = 0; i < m+k; i++) {
		int a, b;
		long long int c;
		scanf("%d %d %lld", &a, &b,&c);
		if (a == 1) {
			update(1, 0, n - 1, b - 1, vec[b-1],c);
			vec[b - 1] = c;
		}
		else {
			printf("%d\n", find(1, 0, n - 1, b-1, c-1));
		}
	}
}