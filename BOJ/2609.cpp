#include<stdio.h>

int main() {
	int num_1, num_2, i,a,b;
	scanf("%d %d", &num_1, &num_2);
	for (i = (num_1 > num_2) ? num_2 : num_1; i > 0; i--) {
		if (num_1%i == 0 && num_2%i == 0) {
			a = i;
			break;
		}
	}
	b = num_1*num_2 / a;
	printf("%d\n%d", a, b);
}