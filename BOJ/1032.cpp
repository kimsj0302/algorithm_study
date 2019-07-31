#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include<algorithm>
#include<string.h>
using namespace std;
int a(int x, int y) {
	int num = x > y ? y : x;
	while (1) {
		if (x%num == 0 && y%num == 0) 
			return num;
		num--;
	}
}
int main() {
	int num;
	int dev;
	char arr1[51],arr2[51];
	scanf("%d", &num);
	scanf("%s", arr1);
	for (int i = 0; i < num-1; i++) {
		//printf("%d  %d ", i + 1, i < num - 1);
		scanf("%s", arr2);
		for (int j = 0; j<strlen(arr1); j++) {
			if (arr1[j] == arr2[j]);
			else
				arr1[j] = '?';
		}
	}
	printf("%s", arr1);

}
