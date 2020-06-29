#include<stdio.h>
long long int a[1000001] = { 0,1,1, };
long long int fibo(int n) {
	if (n<2)
		return a[n];
	if (a[n] != 0)
		return a[n];
	else
		a[n] = (fibo(n - 1) + fibo(n - 2))%1000000007;
	return a[n];
}

int main() {
	int num;
	scanf("%d", &num);
	printf("%lld\n", fibo(num));
} #include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, M;
vector<vector<int>> arr;
vector<vector<int>> cal(int n, int m) {
	if (n == 0) {
		vector<vector<int>> result;
		return result;
	}
	if (m == 1) {
		vector<vector<int>> result;
		for (int i = 1; i <= n; i++) {
			vector<int> tmp;
			tmp.push_back(i);
			result.push_back(tmp);
		}
		return result;
	}
	vector<vector<int>> r1 = cal(n - 1, m);
	vector<vector<int>> r2 = cal(n - 1, m - 1);
	for (int i = 0; i < r2.size(); i++) {
		r2[i].push_back(n);
	}
	vector<vector<int>> result;
	for (int i = 0; i < r1.size(); i++) {
		result.push_back(r1[i]);
	}
	for (int i = 0; i < r2.size(); i++) {
		result.push_back(r2[i]);
	}
	return result;
}

int main() {
	cin >> N >> M;
	vector<vector<int>> arr = cal(N, M);
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}