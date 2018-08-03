#include<iostream>

using namespace std;

int main() {
	int S, T, D;
	scanf("%d %d %d", &S, &T, &D);
	printf("%d\n", ((D / S)*T) / 2);
}