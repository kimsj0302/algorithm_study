#include<iostream>
#include<algorithm>
using namespace std;

int arr[2001][2001];
int sum[2001];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		char x;
		getchar();
		scanf("%c", &x);
		getchar();
		int tmp;
		if (x == 'R') {
			for (int j = 1; j <= m; j++) {
				scanf("%1d", &tmp);
				arr[j][i] = tmp;
				sum[j] += arr[j][i];
			}
		}
		else {
			for (int j = 1; j <= m; j++) {
				scanf("%1d", &tmp);
				arr[j][i]= -tmp;
				sum[j] += arr[j][i];
			}
		}
	}
	int all = 20000000;
	int ind=0;
	for (int i = 1; i <= n; i++) {
		int ma = 0;
		int now = 0;
		for (int j = 1; j <= m; j++) {
			now += (sum[j]-arr[j][i]);
			ma = max(ma, max(now, -now));
		}
		if (all > ma) {
			all = ma;
			ind = i;
		}
	}
	printf("%d\n%d\n", ind, all);
}