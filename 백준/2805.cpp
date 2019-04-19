#include<iostream>
#include<vector>
using namespace std;



int main() {
	long long int n, m;
	scanf("%lld %lld", &n, &m);
	vector<long long int> arr;
	for (long long int i = 0; i < n; i++) {
		long long int tmp;
		scanf("%lld", &tmp);
		arr.push_back(tmp);
	}
	long long int st = 0, nd = 1000000000;
	long long int min = 3000000000;
	long long int p=-1;
	while (st != nd) {
		long long int mid = (st + nd) / 2;
		long long int sum = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] > mid)
				sum += arr[i] - mid;
		}
		if (sum < min && m<=sum) {
			p = mid;
			min = sum;
		}
		if (m <= sum)
			st = mid+1;
		else
			nd = mid;
	}
	long long int mid = (st + nd) / 2;
	long long int sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > mid)
			sum += arr[i] - mid;
	}
	if (sum < min && m <= sum) {
		p = mid;
		min = sum;
	}
	printf("%lld\n", p);
}