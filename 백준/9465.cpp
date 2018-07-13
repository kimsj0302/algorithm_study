#include<iostream>
#include<algorithm>
using namespace std;
int arr[2][100001];
int DP[2][100001];
int len;
int cal(int x, int y) {
	if (DP[x][y] != -1)
		return DP[x][y];
	return DP[x][y] = max(arr[x][y] + cal(1 - x, y + 1), cal(x, y + 1));
}

int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &len);
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < len; k++) {
				scanf("%d", &arr[j][k]);
				DP[j][k] = -1;
				if (k == len - 1)
					DP[j][k] = arr[j][k];
			}
		}
		printf("%d\n", max(cal(0, 0), cal(1, 0)));
	}
}