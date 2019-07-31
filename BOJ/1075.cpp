#include<iostream>
using namespace std;


int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	a = a / 100 * 100;
	int result = (b - a % b)%b;
	if (result < 10) {
		printf("0%d", result);
	}
	else
		printf("%d", result);
}