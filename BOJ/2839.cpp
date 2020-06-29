#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int min = 100000;
	for (int i = 0; i <= n; i += 3) {
		if ((n - i) % 5 == 0) {
			int res = i / 3 + (n - i) / 5;
			if (min > res)
				min = res;
		}
	}
	cout << ((min==100000)?-1:min);
}