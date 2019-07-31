#include<iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int sum = 0;
	while (n != 0) {
		sum += n % 2;
		n = n / 2;
	}
	printf("%d", sum);
}