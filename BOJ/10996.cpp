#include<iostream>
#include<algorithm>
using namespace std;


void print_nb(int n) {
	for (int i = 0; i < n; i++) {
		printf("* ");
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		print_nb((n + 1) / 2);
		printf("\n ");
		print_nb((n ) / 2);
		printf("\n");
	}
}