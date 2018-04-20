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
	int atop, abot, btop, bbot;
	int top, bot,devide;
	scanf("%d %d", &atop, &abot);
	scanf("%d %d", &btop, &bbot);
	top = atop*bbot+ abot*btop;
	bot = abot*bbot;
	devide = a(top, bot);
	printf("%d %d", top/devide, bot/ devide);

}
