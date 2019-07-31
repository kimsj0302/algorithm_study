#include<iostream>

int arr[16];
int pow(int b)
{
	if (b == 0)
		return 1;
	else {
		int re = 1;
		for (int i = 0; i < b; i++)
			re *= 2;
		return re;
	}
}
int main() {
	arr[0] = 2;
	for (int i = 1; i < 16; i++) {
		arr[i] = arr[i - 1] + pow(i - 1);
	}
	int n;
	scanf("%d", &n);
	printf("%d\n", arr[n] * arr[n]);
}