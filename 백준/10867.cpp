#include <algorithm>
#include <iostream>
#include<vector>

using namespace std;

int main() {
	vector <int> a;
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int n;
		scanf("%d", &n);
		a.push_back(n);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < num; i++) {
		if (i == 0 || a[i - 1] != a[i])
			printf("%d ",a[i]);
	}
}
