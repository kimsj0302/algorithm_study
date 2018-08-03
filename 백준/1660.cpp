#include<iostream>
#include<algorithm>
using namespace std;
int DP[300001];
int cal[10001];

int main() {
	int num;
	int total;
	scanf("%d", &total);
	for (int i = 0; i <= total; i++)
		DP[i] = -1;
	cal[1] = 1;
	for (int i = 2; i < 10001; i++) {
		cal[i] = cal[i - 1] + i;
	}
	for(int i = 2; i < 10001; i++) {
		cal[i] += cal[i - 1];
	}
	int full;
	for (int i = 2; i < 10001; i++) {
		if (cal[i] > total) {
			full = i - 1;
			break;
		}
	}
	DP[0] = 0;
	for (int i = 1; i <= total; i++) {
		if (i%cal[1] == 0)
			DP[i] = i / cal[1];
	}
	for (int i = 2; i <= full; i++) {
		int cost = cal[i];
		for (int j = 0; j <= total; j++) {
			if (DP[j] != -1 && j + cost <= total) {
				if (DP[j + cost] == -1)
					DP[j + cost] = DP[j] + 1;
				else
					DP[j + cost] = min(DP[j + cost], DP[j] + 1);
			}
		}
	}


	printf("%d\n", DP[total]);
}