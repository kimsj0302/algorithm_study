#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n;
	vector<int> arr;
	vector<int> number;
	arr.push_back(0);
	scanf("%d", &n);
	int num=0;
	number.push_back(0);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			int tmp;
			scanf("%d", &tmp);
			arr.push_back(tmp);
			num++;
		}
		number.push_back(num);
	}
	for (int i = number.size() - 2; i > 0; i--) {
		for (int j = number[i] + 1; j < number[i + 1]; j++) {
			//printf("[[%d]]", j);
			int tmp = number[i + 1] - number[i]-1;
			arr[j - tmp] += max(arr[j], arr[j + 1]);
		}
	}
	printf("%d\n", arr[1]);
}