#include<iostream>
#include<vector>
#define MOD  1000000
using namespace std;

vector<vector<long long int>> mul(vector<vector<long long int>> &a, vector<vector<long long int>> &b) {
	vector<vector<long long int>> result(2);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			result[i].push_back(0);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			int sum = 0;
			for (int k = 0; k < 2; k++) {
				sum = sum + (a[i][k] * b[k][j])%MOD;
				sum %= MOD;
			}
			result[i][j] = sum % MOD;
		}
	}
	return result;
}
vector<vector<long long int>> cal(vector<vector<long long int>> arr,  long long int k) {
	if (k == 1)
		return arr;
	if (k % 2) {
		vector<vector<long long int>> tmp = cal(arr,  k  - 1 );
		return mul(tmp, arr);
	}
	vector<vector<long long int>> tmp =  cal(arr,  k / 2);

	return mul(tmp, tmp);
}


int main() {
	vector<vector<long long int>> arr(2);
	long long int n;
	scanf("%lld", &n);
	arr[0].push_back(1);
	arr[0].push_back(1);
	arr[1].push_back(1);
	arr[1].push_back(0);
	vector<vector<long long int>> result = cal(arr,  n);
	printf("%lld\n", result[0][1]);
}