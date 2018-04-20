#include<stdio.h>

int main() {
	int N[9], max = 0, i,max_i;
	for (i = 0; i < 9; i++) {
		scanf("%d", &N[i]);
	}
	for (i = 0; i < 9; i++) {
		if (N[i] > max) {
			max = N[i];
			max_i = i;
		}
	}
	printf("%d\n%d", max, max_i+1);
}