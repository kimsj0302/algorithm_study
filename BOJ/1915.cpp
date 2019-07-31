#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001][1001];
int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	int ma = 0;
	for(int i=0;i<x;i++)
		for (int j = 0; j < y; j++) {
			char a;
			scanf("%c", &a);
			if(a=='\n')
				scanf("%c", &a);

			if (a == '1') {
				arr[i][j] = 1;
				ma = 1;
			}
			else
				arr[i][j] = 0;
		}
	for(int i=1;i<x;i++)
		for (int j = 1; j < y; j++) {
			if (arr[i][j] == 0)
				continue;
			if (arr[i - 1][j - 1] == 0 || arr[i - 1][j] == 0 || arr[i][j - 1] == 0) {
				continue;
			}
			else {
				arr[i][j] = 1+min(arr[i - 1][j - 1], min(arr[i - 1][j], arr[i][j - 1]));
				ma = max(ma, arr[i][j]);
			}
		}
	printf("%d\n", ma*ma);
}