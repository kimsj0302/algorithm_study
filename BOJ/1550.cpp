#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include<algorithm>
#include<string.h>
using namespace std;
int main() {
	char arr[7];
	int num,i=0;
	int answer = 0;
	cin >> arr;
	for (int i = 0; arr[i]; i++) {
		//printf("%d ", arr[i]);
		if (arr[i] < 60)
			answer += (arr[i] - '0')*pow(16, strlen(arr)-i-1);
		else
			answer += (arr[i]-'A'+10)*pow(16, strlen(arr) - i-1);
	}
	printf("%d", answer);
}
