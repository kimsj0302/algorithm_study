#include<iostream>
#include<algorithm>
using namespace std;


int main() {
	int arr[1001];
	int t;
	cout << fixed;
	cout.precision(3);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		double sum=0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		sum /= n;
		double per = 0;
		for (int i = 0; i < n; i++) {
			if (sum < arr[i]) per += 1.0;
		}
		cout << 100*per / n << "%"<<endl;
	}
}