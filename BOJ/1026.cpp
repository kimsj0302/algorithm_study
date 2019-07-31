#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include<algorithm>
#include<string.h>
using namespace std;
int a(int x) {
	int binary,sum=0,i=1;
	while (x>0)
	{
		binary = x % 2;
		sum += binary*i;
		x = x / 2;
		i *= 10;
	}
	return sum;
}
int main() {
	int arr1[50],arr2[50];
	int num, i = 0;
	int answer = 0;
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d", &arr1[i]);
	}
	for (i = 0; i < num; i++) {
		scanf("%d", &arr2[i]);
	}
	sort(arr1, arr1 + num);
	sort(arr2, arr2 + num);
	for (i = 0; i < num; i++) {
		answer += arr1[i] * arr2[num - 1 - i];
	}
	printf("%d", answer);
}
