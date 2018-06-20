#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long dp[102][102] = { 0, };
int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		vector<long long> arr,arr2;
		int num2,num3;
		scanf("%d %d", &num2,&num3);
		for (int i = 0; i < num2; i++) {
			int tmp;
			scanf("%d", &tmp);
			arr.push_back(tmp);
		}
		for (int i = 0; i < num3; i++) {
			int tmp;
			scanf("%d", &tmp);
			arr2.push_back(tmp);
		}
		vector<long long > lis(arr.size(), 1);
		vector<long long > lis2(arr2.size(), 1);
		for (int j = 0; j < num2; j++) 
			for (int k = j + 1; k < num2; k++) {
				if (arr[j] < arr[k]) {
					if (lis[k] < lis[j] + 1) {
						lis[k] = lis[j] + 1;
					}
				}
			}
		
		for (int i = 0; i < num2; i++) {
			printf("%d ", lis[i]);
		}
		printf("\n");
		
		for (int j = 0; j < num3; j++) 
			for (int k = j + 1; k < num3; k++) {
				if (arr2[j] < arr2[k]) {
					if (lis2[k] < lis2[j] + 1) {
						lis2[k] = lis2[j] + 1;
					}
				}
			}
		
		for (int i = 0; i < num3; i++) {
			printf("%d ", lis2[i]);
		}
		printf("\n");
		
		
		long long answer = 0;
		for (int i = 0; i < 102; i++) {
			dp[0][i] = 0;
			dp[i][0] = 0;
		}
		if (arr[0] == arr2[0])
			dp[1][1] = answer= 1;
		else
			dp[1][1] = answer= 2;
		for (int i = 1; i <= num2; i++) {
			for (int j = 1; j <= num3; j++) {
				if (i == 1 && j == 1)
					continue;
				if (lis[i - 1] == 1 && lis2[j - 1] == 1) {
					if (arr[i - 1] != arr2[j - 1])
						dp[i][j] = 2;
					else
						dp[i][j] = 1;
					continue;
				}
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (arr[i-1] != arr2[j-1]) {
					if (i > 1)
						if (lis[i - 1] == lis[i - 2])
							dp[i][j]--;
					else if (j > 1)
						if (lis2[j - 1] == lis2[j - 2])
							dp[i][j]--;
					dp[i][j]++;
				}
				answer = max(answer, dp[i][j]);
			}
		}
		answer = max(answer, dp[num2][num3]);
		
		for (int i = 1; i <= num2; i++) {
			for (int j = 1; j <= num3; j++) {
				printf("%d ", dp[i][j]);
			}
			printf("\n");
		}
			
		printf("%lld\n", answer);
	}
}