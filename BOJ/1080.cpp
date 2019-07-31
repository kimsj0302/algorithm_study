#include<iostream>
using namespace std;

char arr[51][51];
char result[51][51];

void change(int x, int y) {
	for (int i = x; i < x + 3; i++)
		for (int j = y; j < y + 3; j++)
			arr[i][j] = arr[i][j]=='1' ? '0' : '1';
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i<n; i++)
		for (int j = 0; j < m; j++) {
			char tmp;
			scanf("%c", &tmp);
			if (tmp == '\n') {
				scanf("%c", &tmp);

			}
			arr[i][j] = tmp;
		}
	for (int i = 0; i<n; i++)
		for (int j = 0; j < m; j++) {
			char tmp;
			scanf("%c", &tmp);
			if (tmp == '\n') {
				scanf("%c", &tmp);

			}
			result[i][j] = tmp;
		}
	int sum = 0;
	for(int i=0;i<=n-3;i++)
		for (int j = 0; j <= m - 3; j++) {
			if (arr[i][j] != result[i][j]) {
				change(i, j);
				sum++;
			}
		}
	for (int i = 0; i<n; i++)
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != result[i][j]) {
				printf("-1\n");
				return 0;
			}
		}
	printf("%d\n", sum);
}