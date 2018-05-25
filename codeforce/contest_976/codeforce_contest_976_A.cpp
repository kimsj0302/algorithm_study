#include<iostream>

using namespace std;

int main() {
	int num;
	scanf("%d", &num);
	getchar();
	int zero = 0;
	bool one = false;
	for (int i = 0; i < num; i++) {
		char tmp;
		scanf("%c", &tmp);
		if (tmp == '0')
			zero++;
		else
			one = true;
	}
	if (one == true)
		printf("1");
	for (int i = 0; i < zero; i++) {
		printf("0");
	}
	printf("\n");
}