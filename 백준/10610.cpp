

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<fstream>
#include<cstring>

using namespace std;


int main() {
	char arr[100001];
	scanf("%s", arr);
	bool is_zero = false;
	int sum=0;
	for (int i = 0; i < strlen(arr); i++) {
		if (arr[i] == '0')
			is_zero = true;
		sum += arr[i] - '0';
	}
	if (sum % 3 == 0 && is_zero) {
		sort(arr, arr + strlen(arr));
		for (int i = strlen(arr) - 1; i >= 0; i--) {
			printf("%c", arr[i]);
		}
	}
	else
		printf("-1");
	printf("\n");
}