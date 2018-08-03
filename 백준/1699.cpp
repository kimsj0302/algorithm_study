#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001];
int DP[100001];
int main() {
	int total;
	scanf("%d", &total);
	for (int i = 0; i <= total; i++)
		DP[i] = -1;
	for (int i = 0; i*i <= total; i++)
		arr[i] = i * i;
	DP[0] = 0;
	for (int i = 0; i <= total; i++) {
		if (i%arr[1] == 0)
			DP[i] = i / arr[1];
	}
	for (int i = 2; i*i <= total; i++) {
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