#include<iostream>

using namespace std;
double DP[1001][2001];
int day, height;
double climb(int d, int c) {
	if (d == day) {
		return c >= height ? 1 : 0;
	}
	if (DP[d][c] != -1.0)
		return DP[d][c];
	return DP[d][c] = (0.25*climb(d + 1, c + 1)) + (0.75*climb(d + 1, c + 2));
}
int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {

		scanf("%d %d", &height, &day);
		for (int k = 0; k < 1001; k++) {
			for (int j = 0; j < 2001; j++) {
				DP[k][j] = -1.0;
			}
		}
		cout.precision(11);
		cout << climb(0, 0) << endl;
	}
}