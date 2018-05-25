#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
long long int a, b, c;
map<long long int, long long int> DP;
long long int cal(long long int num) {
	if (num == 0)
		return 1;
	if (DP[num] != 0)
		return DP[num];
	DP[num]=cal(num / b) + cal(num / c);
	return DP[num];

}
int main() {
	
	scanf("%lld %lld %lld", &a,&b,&c);
	printf("%lld\n",cal(a));
}