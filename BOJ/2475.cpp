#include<stdio.h>

int main() {
	int i, j, k,l,m;
	scanf("%d %d %d %d %d", &i,&j,&k,&l,&m);
	printf("%d", (i*i + j*j + k*k + l*l + m*m) % 10);
}