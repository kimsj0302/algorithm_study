#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		int dest = y - x;
		int n = (int)sqrt(dest);
		if (sqrt(dest) - (int)sqrt(dest) == 0.0) {
			n = n - 1;
		}
		if (n*n+n >= dest) {
			printf("%d\n", 2*n);
		}
		else {
			printf("%d\n", 2*n+1);
		}
	}
}