#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

int t, n;

int main() {
	for (scanf("%d", &t); t > 0; t--) {
		scanf("%d", &n);

		long long int ans = 0;
		vector<int> arr;
		int upper = 0;
		for (int i = 0; i < n; i++) {
			int tmp;
			scanf("%d", &tmp);
			upper = max(upper, tmp);
			arr.push_back(tmp);
		}
		sort(arr.begin(), arr.end());
		vector<int> num(upper+1,0);
		for (int i = 0; i < n; i++) {
			if (num[arr[i]] == 0) {
				for (int j = arr[i]; j <= upper; j += arr[i]) {
					if (num[j] == 0)
						num[j] = arr[i];
				}
			}
		}

		for (int i = 0; i < n; i++) {
			ans += num[arr[i]];
		}
		printf("%lld\n", ans);
	}

	return 0;
}