#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include<algorithm>
using namespace std;
int main() {
	int arr[10];
	int num,i;
	scanf("%d", &num);
	for (i = 0;num; i++) {
		arr[i] = num % 10;
		num = num / 10;
	}
	sort(arr, arr + i);
	for (int j = i-1; j>=0; j--) {
		printf("%d", arr[j]);
	}
}
