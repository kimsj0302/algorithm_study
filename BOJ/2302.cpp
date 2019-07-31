#include<iostream>
#include<vector>
using namespace std;
int table[50] = { 1, };
int DP(int num) {
	if (num < 0)
		return 0;
	if (table[num] != 0)
		return table[num];
	int answer = 0;
	if (num > 1) {
		if (table[num - 2] == 0)
			table[num - 2] = DP(num - 2);
		answer += table[num - 2];
	}
	if (num > 0) {
		if (table[num - 1] == 0)
			table[num - 1] = DP(num - 1);
		answer += table[num - 1];
	}
	return answer;
}
int main() {
	int hole;
	scanf("%d", &hole);
	int num;
	scanf("%d", &num);
	vector<int> arr;
	int answer = 1;
	arr.push_back(0);
	for (int i = 0; i < num; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}
	arr.push_back(hole+1);
	for (int i = 0; i < arr.size() - 1; i++) {
		answer *= DP(arr[i + 1] - arr[i]-1);
	}
	printf("%d\n", answer);
}