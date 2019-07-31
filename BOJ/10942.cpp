#include<stdio.h>
int answer[2001][2001] = { 0, };
int main() {
	int arr[2001];
	int Nnum,Qnum,to,from;
	scanf("%d", &Nnum);
	int i;
	for (i = 0; i < Nnum; i++) {
		scanf("%d", &arr[i]);
		answer[i][i] = 1;
	}
	for (i = 1; i < Nnum; i++) {
		if (arr[i]==arr[i-1])
			answer[i - 1][i] = 1;
		else
			answer[i - 1][i] = 0;

		if(i>1&&arr[i]==arr[i-2])
			answer[i - 2][i] = 1;
		else if(i>1)
			answer[i - 2][i] = 0;
	}
	for (i = 1; i < Nnum; i++) {
		for (int j = 2; j < i; j++) {
			if (arr[i] == arr[i - j - 1])
				answer[i - j - 1][i] = answer[i - j][i - 1];
			else
				answer[i - j - 1][i] = 0;
		}
	}


	/*
	for (i = 0; i < Nnum; i++) {
		for (int j=0; j < Nnum; j++)
			printf("%d ", answer[i][j]);
		printf("\n");
	}*/
	
	scanf("%d", &Qnum);
	for (i = 0; i < Qnum; i++) {
		scanf("%d %d", &from, &to);
		printf("%d\n", answer[from-1][to-1]);
	}
}