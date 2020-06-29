#include<iostream>
using namespace std;
int main() {
	
	int n, m;
	cin >> n >> m;
	int arr[101];
	for (int i = 0; i < n; i++) cin >> arr[i];
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int s = arr[i] + arr[j] + arr[k];
				if (m >= s && max < s) max = s;
			}
		}
	}
	cout << max << endl;
}