#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int arr[3];
	char st[3];
	scanf("%d", &arr[0]);
	scanf("%d", &arr[1]);
	scanf("%d", &arr[2]);
	getchar();
	scanf("%c", &st[0]);
	scanf("%c", &st[1]);
	scanf("%c", &st[2]);
	sort(arr, arr + 3);
	printf("%d %d %d\n", arr[st[0] - 'A'], arr[st[1] - 'A'], arr[st[2] - 'A']);
}