#include<stdio.h>

int main() {
	int N, k;
	int i, j=0;

	scanf("%d %d", &N, &k);
	for (i = 1; i <= N; i++) {
		if (N%i == 0)
			j++;
		if (j == k) {
			printf("%d", i);
			return 0;
		}
	}
	printf("0");
}