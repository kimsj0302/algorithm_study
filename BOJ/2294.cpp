#include<iostream>
#include<algorithm>
using namespace std;
int arr[101];
int DP[10001];
int main() {
	int num;
	int total;
	scanf("%d %d", &num, &total);
	for (int i = 0; i <= total; i++)
		DP[i] = -1;
	for (int i = 0; i < num; i++)
		scanf("%d", &arr[i]);
	DP[0] = 0;
	for (int i = 1; i <= total; i++) {
		if (i%arr[0] == 0)
			DP[i] = i / arr[0];
	}
	for (int i = 1; i < num; i++) {
		int cost = arr[i];
		for (int j = 0; j <= total; j++) {
			if (DP[j] != -1 && j+cost<=total) {
				if (DP[j + cost] == -1)
					DP[j + cost] = DP[j] + 1;
				else
					DP[j + cost] = min(DP[j + cost], DP[j] + 1);
			}
		}
	}


	printf("%d\n", DP[total]);
}
