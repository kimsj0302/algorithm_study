#include<iostream>

using namespace std;

int arr[300];
int find(int x) {
	if (arr[x] == x)
		return x;
	return arr[x] = find(arr[x]);
}

void Union(int x, int y) {
	arr[find(x)] = find(y);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			scanf("%d", &tmp);
			if (tmp == 1) {
				Union(i, j);
			}
		}
	}
	bool isyes = true;
	int base;
	scanf("%d", &base);
	base = find(base);

	for (int i = 1; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (base != find(tmp)) {
			isyes = false;
		}
	}
	if (isyes)
		printf("YES");
	else
		printf("NO");

}