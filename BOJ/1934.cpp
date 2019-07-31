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
	int one,two;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d", &one, &two);
		dev = a(one, two);
		printf("%d\n", one*two / dev);
	}

}
