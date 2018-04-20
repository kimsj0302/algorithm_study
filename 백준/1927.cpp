#include<stdio.h>
void swap(int *q, int *p) {
	int tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}
int com(int a, int b, int c, int d) {
	if (a == 0)
		return 0;
	if (b == 0)
		return c;
	return a < b ? c : d;
}
void pop(int N[], int x) {
	int change;
	change = com(N[2 * x], N[2 * x + 1], 2 * x, 2 * x + 1);
	if (change != 0 && N[change] < N[x]) {
		swap(&N[change], &N[x]);
		pop(N, change);
	}
}
void push(int N[], int x) {
	if (x == 1)
		return;
	if (N[x] < N[x / 2]) {
		swap(&N[x], &N[x / 2]);
		push(N, x / 2);
	}
}
int main() {
	int N[200005] = { 0, }, x, num, j = 1;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &x);
		if (x == 0) {
			printf("%d\n", N[1]);
			N[1] = N[j - 1];
			N[j - 1] = 0;
			pop(N, 1);
			j--;
			if (j < 1)
				j = 1;
		}
		else {
			N[j] = x;
			push(N, j);
			j++;
		}
	}
	return 0;
}