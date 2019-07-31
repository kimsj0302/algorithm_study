#include<iostream>
#include<vector>
using namespace std;


int main() {
	int n;
	scanf("%d", &n);
	vector<long long int> arr;
	for (int i = 0; i < n; i++) {
		long long int tmp;
		scanf("%lld", &tmp);
		arr.push_back(tmp);
	}
	long long int size;
	scanf("%lld", &size);
	long long int ans = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0)
			continue;
		if (arr[i] % size != 0)
			ans += size * (arr[i] / size + 1);
		else
			ans += size * (arr[i] / size);

	}
	printf("%lld\n", ans);

}