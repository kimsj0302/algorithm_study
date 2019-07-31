#include <algorithm>
#include <iostream>
#include<string>

using namespace std;

int main() {
	string a, b;
	getline(cin, a);
	getline(cin, b);
	int size = a.size();
	for (int i = 0; i < size;i++) {
		if (a[i] == '0' || b[i] == '0')
			printf("0");
		else
			printf("1");
	}
	printf("\n");
	for (int i = 0; i < size;i++) {
		if (a[i] =='0' && b[i] == '0')
			printf("0");
		else
			printf("1");
	}
	printf("\n");
	for (int i = 0; i < size;i++) {
		if (a[i] == b[i])
			printf("0");
		else
			printf("1");
	}
	printf("\n");
	for (int i = 0; i < size; i++) {
		if (a[i] == '1')
			printf("0");
		else
			printf("1");
	}
	printf("\n");
	for (int i = 0; i < size; i++) {
		if (b[i] == '1')
			printf("0");
		else
			printf("1");
	}
}

