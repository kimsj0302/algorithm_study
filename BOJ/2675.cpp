#include<stdio.h>

int main() {
	int a;
	scanf("%d", &a);
	for (int i = 0; i<a; i++) {
		int tmp;
		char t[20];
		scanf("%d", &tmp);
		scanf("%s", t);
		for (int i = 0; t[i]; i++) {
			for (int j = 0; j < tmp; j++) {
				printf("%c", t[i]);
			}
		}
		printf("\n");
	}
}