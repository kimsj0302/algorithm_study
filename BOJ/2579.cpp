#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int num;
int arr[301];
int DP[301];
int cal(int ind) {
	if (ind <=0 )
		return 0;
	if (DP[ind] != 0)
		return DP[ind];
	return DP[ind] =  max(arr[ind]+cal(ind - 2), arr[ind]+ arr[ind-1] + cal(ind - 3));
}
int main() {
	scanf("%d", &num);
	for (int i = 1; i <= num; i++) {
		scanf("%d", &arr[i]);
	}
	memset(DP, 0, sizeof(DP));
	DP[1] = arr[1];
	DP[2] = arr[1] + arr[2];
	DP[3] = max(arr[3] + DP[1], arr[3] + arr[2]);

	printf("%d\n", cal(num));
}