#include<stdio.h>
int main() {
	int number, sum;
	int i,j,k;
	int arr[101] = { 0 }, sol[10001] = { 0 };
	scanf("%d %d", &number, &sum);
	for (i = 0; i < number; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < sum+1; i++) {
		sol[i] += (i%arr[0] == 0);
	}
	for (i = 1; i < number; i++)
		for (j = sum; j > 0; j--){
			k = j;
			while (1) {
				k -= arr[i];
				if (k < 0)
					break;
				sol[j] += sol[k];
				
			}
		}
	
	printf("%d", sol[sum]);
}