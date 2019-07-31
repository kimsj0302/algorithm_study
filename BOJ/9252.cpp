#include<stdio.h>
#include<string.h>
int arr[1001][1001] = { 0 };
char a1[1001], a2[1001];
char answer[1001] = { 0, };
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

	answer[arr[a1l - 1][a2l - 1]] = NULL;
	int count = arr[a1l - 1][a2l - 1];
	for (i = a1l - 1; i >= 0; i--)
		for (j = a2l - 1; j >= 0; ) {
			if (i == 0 && arr[i][j - 1] < count) {
				count--;
				answer[count] = a2[j];
				j--;
			}
			else if (j == 0 && arr[i - 1][j] < count) {
				count--;
				answer[count] = a1[i];
				i--;
			}
			else if (i == 0)
				j--;
			else if (j == 0)
				i--;
			else if (arr[i][j - 1] < count &&arr[i - 1][j] < count &&arr[i - 1][j - 1] < count) {
				count--;
				answer[count] = a1[i];
				i--;
				j--;
			}
			else if (arr[i][j - 1] < arr[i - 1][j]) {
				i--;
			}
			else j--;
		}

	printf("%s", answer);
}