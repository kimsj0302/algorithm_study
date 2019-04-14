#include<iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int min, max;
	scanf("%d", &min);
	max = min;
	for (int i = 0; i < n-1; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp > max)
			max = tmp;
		if (tmp < min)
			min = tmp;
	}
	printf("%d\n", min*max);
}