#include<stdio.h>

int main() {
	int y01, y02, y03, y04;
	int y11, y12, y13, y14;
	int y21, y22, y23, y24;
	scanf("%d %d %d %d", &y01, &y02, &y03, &y04);
	scanf("%d %d %d %d", &y11, &y12, &y13, &y14);
	scanf("%d %d %d %d", &y21, &y22, &y23, &y24);
	if (y01 + y02 + y03 + y04 == 4)
		printf("%c\n", 'E');
	else
		printf("%c\n", 68 - (y01 + y02 + y03 + y04));
	if (y11 + y12 + y13 + y14 == 4)
		printf("%c\n", 'E');
	else
		printf("%c\n", 68 - (y11 + y12 + y13 + y14));
	if (y21 + y22 + y23 + y24 == 4)
		printf("%c", 'E');
	else
		printf("%c", 68 - (y21 + y22 + y23 + y24));
}