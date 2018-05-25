#include<iostream>
#include<algorithm>
using namespace std;
int arr[1002][1002] = { 0, };
int vi[1002][1002] = { 0, };
	int r, c;
int cal(int x, int y) {
	if (x > r)
		return 0;
	if (y > c)
		return 0;
	if (vi[x][y])
		return arr[x][y];
	arr[x][y] = arr[x][y]+max(cal(x+1,y), cal(x, y+1));
	vi[x][y] = 1;
	return arr[x][y];
}
int main() {
	scanf("%d %d", &r, &c);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			int tmp;
			scanf("%d", &tmp);
			arr[i][j] = tmp;
		}
	}
	printf("%d\n", cal(1, 1));
}