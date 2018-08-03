#include<stdio.h>
#include<string.h>
int answer[2501][2501] = { 0, };
char arr[2501];
int main() {
	int to, from;
	int min;
	int i;
	int sol[2501] = { 0, };
	scanf("%s", arr);
	min = strlen(arr);
	for (i = 0; i < min; i++) {
		answer[i][i] = 1;
	}

	for (i = 1; i < min; i++) {
		if (arr[i] == arr[i - 1])
			answer[i - 1][i] = 1;
		else
			answer[i - 1][i] = 0;

		if (i>1 && arr[i] == arr[i - 2])
			answer[i - 2][i] = 1;
		else if (i>1)
			answer[i - 2][i] = 0;
	}
	for (i = 1; i < min; i++) {
		for (int j = 2; j < i; j++) {
			if (arr[i] == arr[i - j - 1])
				answer[i - j - 1][i] = answer[i - j][i - 1];
			else
				answer[i - j - 1][i] = 0;
		}
	}
	int cal = 0;
	for (int i = 0; i < min; i++) {
		if (answer[i][min-1] == 1) {
			cal = i;
			break;
		}
	}
	printf("%d\n", min+cal);
}