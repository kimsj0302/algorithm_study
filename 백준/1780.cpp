#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>

using namespace std;
int arr[2200][2200] = { 0, };
int mi = 0, ze = 0, pl = 0;
bool check(int stx, int sty, int ndx,int ndy) {
	int tmp = arr[stx][sty];
	for (int i = stx; i < ndx; i++)
		for (int j = sty; j < ndy; j++)
			if (arr[i][j] != tmp)
				return false;
	if (tmp == -1)
		mi++;
	else if (tmp == 0)
		ze++;
	else
		pl++;
	return true;
}
void f(int stx, int sty, int ndx, int ndy) {
	if (check(stx,sty, ndx,ndy))
		return;
	else {
		int tmp = (ndx-stx) / 3;
		//printf("call\n");
		f(stx, sty, stx + tmp, sty + tmp);
		f(stx+tmp, sty, stx + 2*tmp, sty + tmp);
		f(stx+2*tmp, sty, stx + 3*tmp, sty + tmp);
		f(stx, sty+tmp, stx + tmp, sty + 2*tmp);
		f(stx + tmp, sty + tmp, stx + 2 * tmp, sty + 2 * tmp);
		f(stx + 2 * tmp, sty + tmp, stx + 3 * tmp, sty + 2 * tmp);
		f(stx, sty+ 2 * tmp, stx + tmp, sty + 3 * tmp);
		f(stx + tmp, sty+ 2 * tmp, stx + 2 * tmp, sty + 3 * tmp);
		f(stx + 2 * tmp, sty+ 2 * tmp, stx + 3 * tmp, sty + 3 * tmp);
	}
}
int main() {
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k*k; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr[i / k][i%k] = tmp;
	}
	f(0, 0, k, k);
	printf("%d\n%d\n%d", mi, ze, pl);
}