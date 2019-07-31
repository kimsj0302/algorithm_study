#include<stdio.h>

int main() {
	int N, Ans[100] = { 0, }, S[100] = { 0, }, i, sum = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &Ans[i]);
	}
	for (i = 0; i < N; i++) {
		if (Ans[i] == 1)
			if (i > 0)
				S[i] = S[i - 1] + Ans[i];
			else
				S[i] = 1;
	}
	for (i = 0; i < N; i++) {
		sum += S[i];
	}
	printf("%d", sum);
}