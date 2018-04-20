#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

int main(void) {
	char ch[1000002];
	scanf("%s", ch);
	int i;
	for (i = 0; ch[i]; i++) {
		if ('Z' < ch[i])
			ch[i] = ch[i] - 32;
	}
	int length = i;
	sort(ch, ch + i);


	char now=NULL,answer;
	int num=0, max = 0, is_same=0;
	for (int j = 0; j<=i; j++) {
		if (now != ch[j]) {
			if (num > max) {
				max = num;
				answer = now;
				is_same = 0;
			}
			else if (num == max)
				is_same = 1;
			num = 1;
			now = ch[j];
		}
		else
			num++;
	}
	if (is_same)
		printf("?\n");
	else
		cout << answer << endl;

}
