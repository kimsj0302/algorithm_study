#include<stdio.h>

int main() {
	int arr[1001] = { 0 };
	int num;
	int answer[1001] = { 0, };
	scanf("%d", &num);
	int i,j;
	for (i = 0; i < num; i++)
		scanf("%d", &arr[i]);
	answer[0] = 1;
	int max=1;
	for (i = 1; i < num; i++) {
		answer[i] = 1;
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] < arr[i] && answer[i] <= answer[j]) {
				//printf("-");
				answer[i] = answer[j] + 1;
				if (answer[i] > max)
					max = answer[i];
			}
		}
		//printf("vv%dvv\n", answer[i]);
	}
	printf("%d", max);
}