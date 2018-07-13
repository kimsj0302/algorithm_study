#include<iostream>

using namespace std;
long long arr[101] = { 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 , };
long long DP(int num) {
	if (arr[num] != 0)
		return arr[num];
	else
		return arr[num] = DP(num - 1) + DP(num - 5);
}
int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int tmp;
		scanf("%d", &tmp);
		printf("%lld\n", DP(tmp - 1));
	}
}