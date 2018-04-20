#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std;


int answer[1010][1010];
int sum_arr[1001];

int DP(int st, int nd, vector <int> &num) {
	if (answer[st][nd] != 0)
		return answer[st][nd];
	
	answer[st][nd] = sum_arr[nd]-sum_arr[st-1] - min(DP(st + 1, nd, num), DP(st, nd - 1, num));
	return answer[st][nd];
}



int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 1001; j++)
			for (int k = 0; k < 1001; k++)
				answer[j][k] = 0;
		int case_num;
		int n;
		vector <int> num;
		scanf("%d", &case_num);
		num.push_back(0);
		sum_arr[0] = 0;
		for (int j = 1; j <= case_num; j++) {
			scanf("%d", &n);
			num.push_back(n);
			answer[j][j] = n;
			sum_arr[j] = sum_arr[j - 1] + n;
		}
		printf("%d\n", DP(1, case_num, num));
		
	}

}