#include<iostream>

using namespace std;

int arr[111][111];
int garo[111][111];
int sero[111][111];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			char a;
			scanf("%c", &a);
			if (a == '\n') {
				j--;
				continue;
			}
			if (a == '.')
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (arr[i][j]) {
				garo[i][j] = 1;
				garo[i][j] += garo[i][j - 1];
				garo[i][j - 1] = 0;
			}
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (arr[j][i]) {
				sero[j][i] = 1;
				sero[j][i] += sero[j - 1][i];
				sero[j - 1][i] = 0;
			}
		}
	int ansga = 0, ansse = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (garo[i][j]>1)
				ansga ++;
			if (sero[i][j]>1)
				ansse ++;
		}
	printf("%d %d\n", ansga, ansse);
}