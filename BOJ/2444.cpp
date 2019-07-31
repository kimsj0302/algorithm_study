#include<iostream>

using namespace std;

void prin(int now, int hole) {
	for (int i = 0; i < hole - now; i++)
		printf(" ");
	for (int i = 0; i < now; i++)
		printf("*");
	for (int i = 0; i < now-1; i++)
		printf("*");
	printf("\n");
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		prin(i, n);
	for (int i = n - 1; i >= 1; i--)
		prin(i, n);
}