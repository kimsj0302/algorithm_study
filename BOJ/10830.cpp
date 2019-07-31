#include<iostream>
#include<vector>
#define MOD 1000
using namespace std;

vector<vector<int>> mul(vector<vector<int>> &a, vector<vector<int>> &b, long long int size) {
	vector<vector<int>> result(6);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			result[i].push_back(0);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int sum = 0;
			for (int k = 0; k < size; k++) {
				sum = sum + a[i][k] * b[k][j];
				sum %= MOD;
			}
			result[i][j] = sum % MOD;
		}
	}
	return result;
}
vector<vector<int>> cal(vector<vector<int>> arr, long long int size, long long int k) {
	if (k == 1)
		return arr;
	if (k % 2) {
		vector<vector<int>> tmp = cal(arr, size, k  - 1 );
		return mul(tmp, arr,size);
	}
	vector<vector<int>> tmp =  cal(arr, size, k / 2);

	return mul(tmp, tmp,size);
}


int main() {
	vector<vector<int>> arr(6);
	long long int n, k;
	scanf("%lld %lld", &n, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			scanf("%d", &tmp);
			arr[i].push_back(tmp);
		}
	}
	vector<vector<int>> result = cal(arr, n, k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", result[i][j]%MOD);
		}
		printf("\n");
	}
}