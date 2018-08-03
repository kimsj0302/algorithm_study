#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
	Node * left;
	Node * right;
	int R;
	int L;
	int val = 0;
	Node(int a, int b) {
		left = nullptr;
		right = nullptr;
		R = b;
		L = a;
		val = 0;
	}
};
Node* start[100010];
vector<int> V[100010];
int arr[100001];
int sparse[100010][30];
int height[100010];
void func(int v, int p) {
	height[v] = height[p] + 1;
	sparse[v][0] = p;
	for (int i = 0; i < V[v].size(); i++) {
		if (V[v][i] == p) continue;
		func(V[v][i], v);
	}
}
int LCA(int u, int v) {
	if (height[u] < height[v]) {
		int dif = height[v] - height[u];
		for (int i = 20; i >= 0; i--)
			if ((dif&(1 << i)) != 0)
				v = sparse[v][i];
	}
	if (height[v] < height[u]) {
		int dif = height[u] - height[v];
		for (int i = 20; i >= 0; i--)
			if ((dif&(1 << i)) != 0)
				u = sparse[u][i];
	}
	for (int i = 20; i >= 0; i--) {
		if (sparse[u][i] == sparse[v][i]) continue;
		else {
			u = sparse[u][i];
			v = sparse[v][i];
		}
	}
	if (u == v) return u;
	else return sparse[u][0];
}
Node* insert(int ind, Node * node) {
	Node* newone = new Node(node->L, node->R);
	if (newone->L == newone->R) {
		newone->val = node->val + 1;
		return newone;
	}
	else {
		int mid = (newone->L + newone->R) / 2;
		if (ind <= mid) {
			newone->left = insert(ind, node->left);
			newone->right = node->right;
		}
		else {
			newone->left = node->left;
			newone->right = insert(ind, node->right);
		}
		newone->val = newone->right->val + newone->left->val;
		return newone;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n - 1; i++) {
		int st, nd;
		scanf("%d %d", &st, &nd);
		V[st].push_back(nd);
		V[nd].push_back(st);
	}
	func(1, 0);
	for (int j = 1; j < 20; j++)
		for (int i = 1; i <= n; i++)
			sparse[i][j] = sparse[sparse[i][j - 1]][j - 1];

	start[0] = new Node(1, 1000000);

	queue<Node*> que;
	que.push(start[0]);
	int count = 0;
	while (!que.empty()) {
		count++;
		Node * tmp = que.front();
		que.pop();
		if (tmp->L == tmp->R) continue;
		int h = (tmp->L + tmp->R) / 2;
		Node * _left = new Node(tmp->L, h);
		Node * _right = new Node(h+1, tmp->R);
		tmp->left = _left;
		tmp->right = _right;
		que.push(_left);
		que.push(_right);
	}


	queue<int> que2;
	que2.push(1);
	while (!que2.empty()) {
		int tmp = que2.front();
		que2.pop();
		start[tmp] = insert( arr[tmp],start[sparse[tmp][0]]);
		for (int i = 0; i < V[tmp].size(); i++) {
			if (V[tmp][i] == sparse[tmp][0]) continue;
			que2.push(V[tmp][i]);
		}
	}


	int a;
	scanf("%d", &a);
	for (int i = 1; i <= a; i++) {
		int u, v, k;
		scanf("%d %d %d", &u, &v, &k);
		int lca = LCA(u, v);
		int ans = 0;

		Node* N1 = start[u];
		Node* N2 = start[v];
		Node* N3 = start[lca];
		Node* N4 = start[sparse[lca][0]];

		int sum = 0;
		while (1) {

			if (N1->L == N1->R)
			{
				if (sum + 1 <= k) ans = N1->L;
				break;
			}
			int s = sum + N1->left->val + N2->left->val - N3->left->val - N4->left->val + 1;
			if (s > k) {
				N1 = N1->left;
				N2 = N2->left;
				N3 = N3->left;
				N4 = N4->left;
			}
			else {
				ans = (N1->L + N1->R) / 2 + 1;
				sum += N1->left->val + N2->left->val - N3->left->val - N4->left->val;
				N1 = N1->right;
				N2 = N2->right;
				N3 = N3->right;
				N4 = N4->right;
			}
		}
		printf("%d\n", ans);
	}


}