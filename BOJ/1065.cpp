#include<iostream>
using namespace std;

bool is_hansu(int n) {
	if (n < 10)
		return true;
	int sub = n % 10 - n/10%10;
	n /= 10;
	while (n/10) {
		if (sub != n % 10 - n / 10 % 10)
			return false;
		n = n / 10;
	}
	return true;
}
int main() {
	int n;
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (is_hansu(i))
			sum++;
	}
	printf("%d", sum);

}