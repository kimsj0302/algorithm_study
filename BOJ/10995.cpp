#include<iostream>

using namespace std;

void prin(int n) {
	for (int i = 1; i <= n; i++) {
		printf("*");
		if (i != n)
			printf(" ");
	}
	printf("\n");
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0)
			printf(" ");
		prin(n);
	}
}