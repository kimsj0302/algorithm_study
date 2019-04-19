#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main() {
	long long int n, c;
	scanf("%lld %lld", &n, &c);
	vector<long long int> arr;
	for (long long int i = 0; i < n; i++) {
		long long int tmp;
		scanf("%lld", &tmp);
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	long long int st = 0, nd = 1000000000, min = 0;
	while (st != nd) {
		long long int mid = (st + nd) / 2;
		
		long long int now = arr[0];
		long long int num = 1;
		for (long long int i = 1; i < n; i++) {
			if (arr[i] - now >= mid) {
				now = arr[i];
				num++;
			}
		}
		if (num >= c && mid > min) {
			min = mid;
		}
		if (num >= c)
			st = mid+1;
		else
			nd = mid;

	}
	long long int mid = (st + nd) / 2;

	long long int now = arr[0];
	long long int num = 1;
	for (long long int i = 1; i < n; i++) {
		if (arr[i] - now >= mid) {
			now = arr[i];
			num++;
		}
	}
	if (num >= c && mid > min) {
		min = mid;
	}
	printf("%lld\n", min);
}