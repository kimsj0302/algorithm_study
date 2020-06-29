#include<iostream>
#include<map>
using namespace std;

int main() {
	int n;	
	scanf("%d", &n);
	map<int, int> a;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		a[tmp]++;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (a[tmp] == 0)
			printf("0\n");
		else {
			printf("1\n");
		}
	}
}