#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include<algorithm>
#include<string.h>
using namespace std;

int main() {
	char arr[51];
	int num, i = 0;
	int answer = 10;
	scanf("%s", arr);
	for (i = 1; arr[i]; i++) {
		if (arr[i - 1] == arr[i])
			answer += 5;
		else
			answer += 10;
	}
	cout << answer;
}
