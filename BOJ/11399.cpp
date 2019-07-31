#include<stdio.h>
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void quick_sort(int* array, int start, int end) {

	if (start >= end) return;

	int mid = (start + end) / 2;
	int pivot = array[mid];

	swap(&array[start], &array[mid]);

	int p = start + 1, q = end;

	while (1) {
		while (array[p] <= pivot) { p++; }
		while (array[q]>pivot) { q--; }

		if (p>q) break;

		swap(&array[p], &array[q]);
	}

	swap(&array[start], &array[q]);

	quick_sort(array, start, q - 1);
	quick_sort(array, q + 1, end);

}

int main(void) {

	int array[1001] = { 0, };
	int i;
	int num;
	scanf("%d", &num);
	for (i = 0; i < num; i++)
		scanf("%d", &array[i]);

	quick_sort(array, 0, num-1);

	int answer = 0;
	for (i = 0; i < num; i++) {
		answer += (num - i)*array[i];
	}
	printf("%d", answer);
	return 0;
}
