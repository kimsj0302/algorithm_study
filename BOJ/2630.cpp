#include<iostream>
using namespace std;
int arr[129][129];
int blue = 0, white = 0;
pair<int, int> cal(int x1, int y1, int x2, int y2) {
	if (x1 == x2 && y1 == y2)
	{
		if (arr[x1][y1] == 0) white++;
		else blue++;
		return make_pair(1, arr[x1][y1]);
	}
	int midx = (x1 + x2) / 2, midy = (y1 + y2) / 2;
	pair<int, int> lu = cal(x1, y1, midx, midy);
	pair<int, int> ld = cal(midx+1, y1, x2, midy);
	pair<int, int> ru = cal(x1, midy+1, midx, y2);
	pair<int, int> rd = cal(midx + 1, midy + 1, x2, y2);
	if (lu.second == 2 || ld.second == 2 || ru.second == 2 || rd.second == 2) {
		return make_pair(lu.first + ld.first + ru.first + rd.first, 2);
	}
	if (lu.second == ld.second && lu.second == ru.second && lu.second == rd.second) {
		if (lu.second == 0) {
			white -= 3;
		}
		else blue -= 3;
		return make_pair(1, lu.second);
	}

	return make_pair(lu.first + ld.first + ru.first + rd.first, 2);
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	cal(1, 1, n, n);
	printf("%d\n%d\n", white,blue);
}