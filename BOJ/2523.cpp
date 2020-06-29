#include<iostream>
#include<algorithm>
using namespace std;


void print_n(int n) {
	for (int i = 0; i < n; i++) {
		printf("*");
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		print_n(i);
		printf("\n");
	}

	for (int i = n; i > 0; i--) {
		print_n(i);
		printf("\n");
	}
}