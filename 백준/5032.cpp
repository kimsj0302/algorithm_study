#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	a = a + b;
	int sum = 0;
	while (a >= c) {
		sum += a / c;
		a = a - a / c * (c-1);
	}
	printf("%d\n", sum);
}