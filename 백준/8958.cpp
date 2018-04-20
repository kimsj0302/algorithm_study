#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int num1;
	char arr[81];
	int num=0,answer=0;
	scanf("%d", &num1);
	for (int j = 0; j<num1; j++) {
		answer = 0;
		num = 0;
		scanf("%s", arr);
		for (int i = 0; arr[i]; i++) {
			if (arr[i] == 'O') {
				++num;
				//printf("--num=%d\n", num);
				answer += num;
			}
			else {
				num = 0;
			}

		}
		printf("%d\n", answer);
	}
}