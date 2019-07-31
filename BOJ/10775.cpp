#include<iostream>

using namespace std;
int arr[100001];

int find(int x) {
	if (arr[x] == x)
		return x;
	else
		return arr[x] = find(arr[x]);
}

int main() {
	int gate, plane;
	scanf("%d %d", &gate, &plane);
	for (int i = 0; i <= gate; i++) {
		arr[i] = i;
	}
	int num = 0;
	for (int i = 0; i < plane; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (find(tmp) == 0)
			break;
		arr[find(tmp)] = find(tmp) - 1;
		num++;
	}
	printf("%d\n", num);
}