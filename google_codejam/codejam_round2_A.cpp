#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
int main() {
	int under;
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int L, N;
		scanf("%d %d", &L, &N);
		under = L;
		vector<int> arr;
		vector<pair<int,int>> answer;
		int j;
		for (j = 0; j < N; j++) {
			int tmp;
			scanf("%d", &tmp);
			arr.push_back(tmp);
			answer.push_back(make_pair(0, j));
			L -= tmp;
		}
		for (; j < under; j++) {
			arr.push_back(0);
			answer.push_back(make_pair(0, j));
		}
		for (j = 0; j < arr.size(); j++) {
			
			int tmp = arr[j];
			if (100%under==0 && under<=100)
				break;
			if ((int)((float)(100 * arr[j]) / under + 0.5) > (float)(100 * arr[j]) / under)
				continue;
			else
				while ((int)((100.0 * arr[j]) / under + 0.5) <= (100.0 * arr[j]) / under) {
					arr[j] += 1;
					answer[j].first += 1;
				}
			arr[j] = tmp;
		}
		int total=1;
		while ((int)((100.0 *total) / under + 0.5) <= (100.0 * total) / under && total<L) {
			total++;
		}
		for (; j < under; j++) {
			answer[j].first = total;
		}
		sort(answer.begin(), answer.end());
		for (int j = 0; j < answer.size(); j++) {
			if (L - answer[j].first < 0) {
				arr[answer[j].second] += L;
				L = 0;
				break;
			}
			L -= answer[j].first;
			arr[answer[j].second] += answer[j].first;
		}
		arr[answer[j-1].second] += L;
		int result = 0;
		for (int j = 0; j < arr.size(); j++) {
			result += (int)((100.0 * arr[j]) / under + 0.5);
		}
		printf("Case #%d: %d\n", i+1,result);
	}
}