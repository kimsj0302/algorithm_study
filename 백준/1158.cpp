#include <stdio.h>


void killer(int n,int k) {
	int  i, *a= new int[n];
	int count = 0, die = 0;
	for (i = 0; i<n; i++)
		a[i] = 1;
	for (i = 0; die<n - 1; i++) {
		if (a[i%n] != 0) count++;
		if (a[i%n] != 0 && count == k) {
			count = 0;
			die++;
			a[i%n] = 0;
			printf("%d, ", i%n + 1);
		}
	}
	for (i = 0; i<n; i++) {
		if (a[i] != 0) printf("%d>", i + 1);
	}
}

int main() {
	int n,k;
	scanf("%d %d", &n, &k);
	printf("<");
	killer(n,k);
}