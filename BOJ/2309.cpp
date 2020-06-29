#include<iostream>
#include<algorithm>
using namespace std;
int arr[9];
bool cal(int a, int b, int c, int d, int e, int f, int g) {
	if (a + b + c + d + e + f + g == 100) {
		printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n", a, b, c, d, e, f, g);
		return true;
	}
	return false;
}
int main() {
	for (int i = 0; i < 9; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + 9);
	for (int q = 0; q < 9; q++)
		for (int w = q + 1; w < 9; w++)
			for (int e = w + 1; e < 9; e++)
				for (int r = e + 1; r < 9; r++)
					for (int t = r + 1; t < 9; t++)
						for (int y = t + 1; y < 9; y++)
							for (int u = y + 1; u < 9; u++)
								if (cal(arr[q], arr[w], arr[e], arr[r], arr[t], arr[y], arr[u]))
									return 0;
}