#include<iostream>
using namespace std;
int TT[100001] = { 0, };
int FT[100001] = { 0, };
int TF[100001] = { 0, };
long long DP(bool right, bool left,int num) {
	if (num == 0)
		return 1;
	int answer = 0;
	if (TT[num] == 0) {
		TT[num] = DP(true, true, num - 1);
	}
	answer += TT[num];
	if (right) {
		if (FT[num] == 0)
			FT[num] = DP(false, true, num - 1);
		answer += FT[num];
	}
	if (left) {
		if(TF[num]==0)
			TF[num]=DP(true, false, num - 1);
		answer += TF[num];
	}
	return answer % 9901;
	
}
int main() {
	int num;
	scanf("%d", &num);
	
	printf("%lld\n", DP(true, true, num)%9901);
}