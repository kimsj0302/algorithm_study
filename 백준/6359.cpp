#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		vector<int> arr(num+1,1);
		int ans = num;
		for (int i = 2; i <= num; i++) {
			for (int j = i; j <= num; j += i) {
				if (arr[j] == 1) {
					ans--;
					arr[j] = 0;
				}
				else {
					ans++;
					arr[j] = 1;
				}
			}
		}
		printf("%d\n", ans);
	}
}