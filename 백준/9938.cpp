#include<iostream>

using namespace std;
int arr[300000];
int exist[3000000];

int find(int x) {
	if (arr[x] == x)
		return x;
	else
		return arr[x] = find(arr[x]);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		arr[i] = i;
		exist[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d",&a, &b);
		int roota = find(a);
		int rootb = find(b);
		if (exist[roota] && exist[rootb]) {
			printf("SMECE\n");
			continue;
		}
		printf("LADICA\n");
		if (exist[roota]) {
			arr[rootb] = roota;
			exist[rootb] = 1;
		}
		else {
			arr[roota] = rootb;
			exist[roota] = 1;
		}
	}
}