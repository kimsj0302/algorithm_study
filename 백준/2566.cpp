#include<stdio.h>

int main() {
	int N[9][9], max = 0, i,j, max_j, max_i;
	for (i = 0; i < 9; i++)
		for (j = 0; j<9; j++)
			scanf("%d", &N[i][j]);
	for (i = 0; i < 9; i++) 
		for(j=0;j<9;j++){
		if (N[i][j] > max) {
			max = N[i][j];
			max_i = i;
			max_j = j;
		}
	}
	printf("%d\n%d %d", max, max_i+1,max_j+1);
}