#include<iostream>
using namespace std;

int arr[1000001];
int main() {
	long long min, max;
	scanf("%lld %lld", &min, &max);
	for (long long i = 2; i*i <= max; i++) {
		long long now = min / (i*i);
		if (now*i*i < min) {
			now++;
		}
		for (; now*i*i <= max; now++) {
			arr[now*i*i - min] = 1;
		}
	}
	long long sum = 0;
	for (long long i = 0; i <= max - min; i++) {
		sum += 1-arr[i];
	}
	printf("%lld\n", sum);
}