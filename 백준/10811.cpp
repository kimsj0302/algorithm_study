#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int num, order;
	scanf("%d %d", &num, &order);
	vector <int> a;
	int st, nd;
	a.push_back(0);
	for (int i = 1; i <= num; i++) {
		a.push_back(i);
	}
	for (int i = 0; i < order; i++) {
		scanf("%d %d", &st, &nd);
		reverse(a.begin() + st, a.begin() + nd+1);
		//for (int i = 1; i <= num; i++) {
		//	printf("%d ", a[i]);
		//}
		//printf("\n");
	}
	for (int i = 1; i <= num; i++) {
		printf("%d ", a[i]);
	}
}

