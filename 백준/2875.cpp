#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<fstream>

using namespace std;


int main() {
	int W, M, I;
	scanf("%d %d %d", &W, &M, &I);
	int team;
	if (W >= M * 2) {
		team = M;
	}
	else
		team = W / 2;
	if (W + M - team * 3 - I < 0) {
		int tmp = I - (W + M - team * 3);
		if (tmp % 3 == 0)
			team -= tmp / 3;
		else
			team -= tmp / 3+1;
	}
	printf("%d\n", team);
}