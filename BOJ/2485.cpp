#include<stdio.h>

void m(int *ptr, int *a, int N) {
	int i,before;
	*a = *(ptr+1) - *ptr;
	for (i = 1; i < N-1; i++) {
		before = *(ptr + i) - *(ptr+i-1);
		//printf("before=%d when i=%d\n\n", before, i);
		*a = gdc(*a, before);
		if (*a == 1)
			break;
	}
}

int gdc(int u, int v) //최대공약수를 반환하는 함수
{
	
	int t;
	while (u) {
		if (u < v) {
			t = u; u = v; v = t;
		}
		u = u - v;
	}
	return v;

}

int main() {
	int i, N, a;
	scanf("%d", &N);
	int* ptr = (int*)malloc(N * 10);
	for (i = 0; i < N; i++) {
		scanf("%d", (ptr+i));
	}

	m(ptr, &a, N);
	//printf("a=%d\n\n", a);
		printf("%d", (*(ptr+N - 1) - *ptr) / a - N+1);
}