#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int num;
	int arr[10];
	scanf("%d", &num);
	for (int j = 0; j<num; j++) {
		for (int i = 0; i<10; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr + 10);
		printf("%d\n", arr[7]);
	}
}