#include<iostream>

using namespace std;

int main() {
	int a;
	long long int  ans = 1;
	scanf("%d", &a);
	for (long long int i = 2; i <= a; i++) {
		ans *= i;
		while(ans%10==0)
			ans/=10;
		ans%=1000000;
		
		
	}
	printf("%lld", ans % 10);
}