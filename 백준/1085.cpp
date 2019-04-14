#include<iostream>
using namespace std;

int min(int a, int b) {
	return a > b ? b : a;
}
int main() {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	printf("%d", min(min(c - a, a), min(d - b, b)));
}