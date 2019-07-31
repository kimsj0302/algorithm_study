#include<iostream>
using namespace std;
//W==1 B==0
int board[8][8] = { 1,0,1,0,1,0,1,0,   0,1,0,1,0,1,0,1 ,1,0,1,0,1,0,1,0,   0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,   0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,   0,1,0,1,0,1,0,1 };
int newboard[50][50];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char a;
			scanf("%c", &a);
			if (a == '\n') {
				j--;
				continue;
			}
			if (a == 'W')
				newboard[i][j] = 1;
			else
				newboard[i][j] = 0;
		}
	int stx, sty;
	int min = 64;
	for (int stx = 0; stx <= n - 8; stx++) {
		for (int sty = 0; sty <= m - 8; sty++) {
			int sums = 0;
			int sumns = 0;
			for (int i = stx; i < stx + 8; i++) {
				for (int j = sty; j < sty + 8; j++) {
					if (board[i - stx][j - sty] != newboard[i][j]) {
						sums++;
					}
					else {
						sumns++;
					}
				}
			}
			if (sums < min) {
				min = sums;
			}
			if (sumns < min) {
				min = sumns;
			}
		}
	}
	printf("%d\n",min);
}