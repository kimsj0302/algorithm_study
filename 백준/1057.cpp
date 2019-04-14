#include<iostream>
using namespace std;

int main() {
	int num, n, m;
	scanf("%d %d %d", &num, &n, &m);
	int count = 0;
	while (n != m) {
		n = (n + 1) / 2;
		m = (m + 1) / 2;
		count++;
	}
	printf("%d", count);

}