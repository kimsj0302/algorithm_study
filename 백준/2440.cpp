#include<stdio.h>

int main() {
	int i, j, k;
	scanf("%d", &i);
	for (j = 1; j <= i; j++) {
		for (k = 0; k <=i- j; k++)
			printf("*");
		printf("\n");
	}
}