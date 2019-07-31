#include<stdio.h>
int num1, num2;
void printarr(int arr[][501]) {
	for (int i = 0; i < num1; i++) {
		for (int j = 0; j < num2; j++)
			printf("%d", arr[i][j]);
		printf("\n");
	}
}
int area(int arr[][501], int x, int y) {
	if (arr[x][y] == 0)
		return 0;
	if (x >= num1 || y >= num2 || x < 0 || y < 0)
		return 0;
	if (arr[x][y]) {
		//printarr(arr);
		arr[x][y] = 0;
		return 1 + area(arr,x,y-1)+ area(arr, x, y+1)+ area(arr, x-1, y)+ area(arr, x+1, y);
	}
}
int main() {
	int arr[501][501] = { 0, },i,j;
	int max = 0,count=0,tmp;
	scanf("%d %d", &num1, &num2);
	for (i = 0; i < num1; i++)
		for (j = 0; j < num2; j++)
			scanf("%d", &arr[i][j]);
	for (i = 0; i < num1; i++)
		for (j = 0; j < num2; j++) {
			if (arr[i][j]) {
				tmp = area(arr, i, j);
				if (tmp > max)
					max = tmp;
				count++;

			}
		}
	printf("%d\n%d", count, max);
}