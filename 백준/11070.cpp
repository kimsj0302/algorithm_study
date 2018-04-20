#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;


float W(float S, float A) {
	if (S*S + A*A == 0.0)
		return -1;
	else
		return (S*S / (S*S + A*A));
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int n, m;
		scanf("%d %d", &n, &m);
		int team[1010][3] = { 0, };
		int team1, team2, score1, score2;
		for (int j = 0; j < m; j++) {
			scanf("%d %d %d %d", &team1, &team2, &score1, &score2);
			team[team1][0] += score1;
			team[team1][1] += score2;
			team[team2][1] += score1;
			team[team2][0] += score2;
		}
		vector <int> num;
		int out=0;
		for (int j = 1; j <= n; j++) {
			float a;
			a = W((float)team[j][0], (float)team[j][1])*1000;
			if (a < 0)
				num.push_back(0);
			else
				num.push_back((int)a);
		}
		sort(num.begin(), num.end());
		printf("%d\n%d\n", num[n-1],num[0]);
	}
}