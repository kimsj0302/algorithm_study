#include<iostream>
#include<string>
using namespace std;
int dp[5001];
string a;
long long int cal(int ind) {
	if (ind < 0)
		return 1;
	if (dp[ind] != 0)
		return dp[ind];
	long long int sum = 0;
	if (ind > 0) {
		int num;
		num = a[ind] - '0';
		num += (a[ind - 1] - '0') * 10;
		if (10 <= num && num <= 26)
			sum += cal(ind - 2);
	}
	if (a[ind] != '0')
		sum += cal(ind - 1);
	return dp[ind] = sum % 1000000;
}

int main() {
	cin >> a;
	printf("%lld\n", cal(a.size() - 1) % 1000000);
}