#include<iostream>
#include<algorithm>
using namespace std;


void print_n(int n) {
	for (int i = 0; i < n; i++) {
		printf("*");
	}
}
void print_b(int n) {
	for (int i = 0; i < n; i++) {
		printf(" ");
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = n; i > 0; i--) {
		print_b(n - i);
		print_n(i*2-1);
		printf("\n");
	}

	for (int i = 2; i <=n; i++) {
		print_b(n - i);
		print_n(i * 2 - 1);
		printf("\n");
	}
}