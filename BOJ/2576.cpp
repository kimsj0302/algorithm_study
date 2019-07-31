#include<stdio.h>

int main() {
	int N[7], min = 100, i,sum=0;
	for (i = 0; i < 7; i++){
			scanf("%d", &N[i]);
	}
	for (i = 0; i < 7; i++) {
		if (N[i] % 2 == 1) {
			if (N[i] < min) {
				min = N[i];
			}
			sum += N[i];
		}
	}
	if (min == 100)
		printf("-1");
	else
	printf("%d\n%d", sum, min);
}