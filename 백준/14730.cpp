#include<iostream>
#include<map>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	long long int sum = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		long long int tmp = (a*b);
		sum = (sum + tmp) ;
	}
	printf("%lld\n", sum);
}