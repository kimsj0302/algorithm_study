#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool arr[1000010];
	int a, b;
	cin >> a >> b;
	for (int i = 0; i <= b; i++) {
		arr[i] = true;
	}
	arr[0] = false;
	arr[1] = false;
	for (int i = 2; i <= b / 2; i++) {
		if (!arr[i]) continue;
		for (int j = i + i; j <= b; j += i) {
			arr[j] = false;
		}
	}
	for (int i = a; i <= b; i++) {
		if (arr[i]) cout << i << "\n";
	}
}