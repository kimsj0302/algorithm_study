#include<iostream>
#include<vector>
using namespace std;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	vector<int> arr;
	arr.push_back(0);
	int sum = 0;
	for (int i = 0; i < a; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp + arr[arr.size()-1]);
	}
	for(int i=0;i<a;i++)
		for (int j = i + 1; j <= a; j++) {
			if (arr[j] - arr[i] == b)
				sum++;
		}
	printf("%d", sum);
}
