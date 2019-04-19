#include<iostream>
#include<vector>
using namespace std;

long long int arr[100000];

long long int cal(int size, int st, int nd) {
	if (st == nd)
		return arr[st];
	int l = (st + nd) / 2;
	int r = (st + nd) / 2 + 1;
	long long int left = cal(size, st,l);
	long long int right = cal(size, r, nd);
	long long int max = left > right ? left : right;
	long long int hight = arr[r] > arr[l] ? arr[l] : arr[r];
	max = 2 * hight > max ? 2 * hight : max;
	while (l != st || r != nd) {
		if (l == st) {
			r++;
			hight = hight < arr[r] ? hight : arr[r];
		}
		else if (r == nd) {
			l--;
			hight = hight < arr[l] ? hight : arr[l];
		}
		else {
			if (arr[l - 1] < arr[r + 1]) {
				r++;
				hight = hight < arr[r] ? hight : arr[r];
			}
			else {
				l--;
				hight = hight < arr[l] ? hight : arr[l];
			}
		}
		if (max < (r-l+1)*hight)
			max = (r-l+1)*hight;
	}
	return max;
}


int main() {
	while (1) {
		int n;
		scanf("%d", &n);
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			scanf("%lld", &arr[i]);
		}
		printf("%lld\n", cal(n, 0, n - 1));
	}

}