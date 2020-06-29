#include<iostream>
using namespace std;
int main() {
	int arr[15][15] = { {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14} };
	for (int i = 1; i <= 14; i++) {
		for (int j = 0; j <= 14; j++) {
			if (j == 0) arr[i][j] = arr[i - 1][j];
			else arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int k, n;
		cin >> k >> n;
		cout << arr[k][n] << endl;
	}
}