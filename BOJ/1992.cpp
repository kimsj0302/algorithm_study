#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>

using namespace std;
char arr[64][64];
bool check(int stx, int sty, int ndx, int ndy) {
	int tmp = arr[stx][sty];
	for (int i = stx; i < ndx; i++)
		for (int j = sty; j < ndy; j++)
			if (tmp != arr[i][j])
				return false;
	return true;
}
void quad(int stx, int sty, int ndx, int ndy) {
	if (check(stx, sty, ndx, ndy)) {
		printf("%c", arr[stx][sty]);
	}
	else if (ndx - stx == 1) {
		printf("%c", arr[stx][sty]);
	}
	else {
		printf("(");
		int len = ndx - stx;
		quad(stx, sty, stx + len / 2, sty + len / 2);
		quad(stx, sty + len / 2, stx + len / 2, sty + len);
		quad(stx + len / 2, sty, stx + len, sty + len / 2);
		quad(stx + len / 2, sty + len / 2, stx + len, sty + len);
		printf(")");
	}
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char tmp;
			scanf("%c", &tmp);
			if (tmp == '\n') {
				j--;
				continue;
			}
			arr[i][j] = tmp;
		}
	}
	quad(0, 0, n, n);
	printf("\n");
}