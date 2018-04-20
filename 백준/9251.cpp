#include<stdio.h>
#include<string.h>
int arr[1001][1001] = { 0 };
char a1[1001], a2[1001];

int main() {

	scanf("%s", a1);
	scanf("%s", a2);
	int i, j, a1l, a2l;
	a1l = strlen(a1);
	a2l = strlen(a2);
	for (i = 0; a1[i]; i++)
		for (j = 0; a2[j]; j++) {
			if (a1[i] == a2[j]) {
				if (i == 0 || j == 0)
					arr[i][j] = 1;
				else 
					arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else {
				if (i == 0)
					arr[i][j] = arr[i][j - 1];
				else if (j == 0)
					arr[i][j] = arr[i - 1][j];
				else arr[i][j] = arr[i - 1][j] > arr[i][j - 1] ? arr[i - 1][j] : arr[i][j - 1];
			}
		}
	printf("%d\n", arr[i - 1][j - 1]);
}