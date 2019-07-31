#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a > b - c) {
			printf("do not advertise\n");
		}
		else if (a == b - c) {
			printf("does not matter\n");
		}
		else {
			printf("advertise\n");
		}
	}
}