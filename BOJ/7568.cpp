#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int w[51], h[51];
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		w[i] = a;
		h[i] = b;
	}
	for (int i = 0; i < n; i++) {
		int num = 1;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (w[i] < w[j] && h[i] < h[j]) num++;
		}
		cout << num << " ";
	}
	cout << endl;
}