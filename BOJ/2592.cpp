#include<stdio.h>

int main() {
	int N[10], val_1=0, i, j, val_2, num, M_num=0,M_val;
	for (i = 0; i < 10; i++) {
		scanf("%d", &N[i]);
	}
	for (i = 0; i < 10; i++) {
		val_1 += N[i];
	}
	val_1 = val_1 / 10;
	for (i = 0; i < 10; i++) {
		num = 0;
		for (j = i; j < 10; j++)
			if (N[i] == N[j])
				num++;
		if (num > M_num) {
			M_num = num;
			M_val = N[i];
		}
		
	}
	printf("%d\n%d", val_1, M_val);
}