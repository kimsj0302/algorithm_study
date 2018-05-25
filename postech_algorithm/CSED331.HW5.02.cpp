#include<iostream>/
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		vector<int> numbers;
		int n;
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			int tmp;
			scanf("%d", &tmp);
			numbers.push_back(tmp);
		}
		vector<long long> inc(n, 1);
		vector<long long> inc_(n, 0);
		vector<long long> dec(n, 1);
		vector<long long> dec_(n, 0);
		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (numbers[j] < numbers[k]) {
					if (inc[k] < inc[j] + 1) {
						inc[k] =  (inc[j] + 1) % 20170429;
					}
				}
			}
		}
		for (int j = 0; j < n; j++) {
			if (inc_[j] == 0)
				inc_[j] = 1;
			for (int k = j + 1; k < n; k++) {
				if (numbers[j] < numbers[k]) {
					if (inc[k] == inc[j] + 1) {
						inc_[k] += inc_[j] % 20170429;
					}
				}
			}
		}
		reverse(numbers.begin(), numbers.end());
		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (numbers[j] < numbers[k]) {
					if (dec[k] < dec[j] + 1) {
						dec[k] = (dec[j] + 1) % 20170429;
					}
				}
			}
		}
		for (int j = 0; j < n; j++) {
			if (dec_[j] == 0)
				dec_[j] = 1;
			for (int k = j + 1; k < n; k++) {
				if (numbers[j] < numbers[k]) {
					if (dec[k] == dec[j] + 1) {
						dec_[k] += dec_[j] % 20170429;
					}
				}
			}
		}
		reverse(dec.begin(), dec.end());
		reverse(dec_.begin(), dec_.end());
		long long answer = 0;
		long long max_num= 0;
		for (int j = 0; j < n; j++) {
			if (max_num == inc[j] + dec[j]) {
				answer+=(dec_[j]*inc_[j]) % 20170429;
			}
			else if (max_num < inc[j] + dec[j]) {
				max_num = inc[j] + dec[j];
				answer = (dec_[j] * inc_[j]) % 20170429;
			}
			answer %=  20170429;
		}
		printf("%lld\n", answer % 20170429);
	}
}