#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct _node {
	struct _node* next;
} node;

typedef struct _stack {
	int count;
	node* top;
}stack;
void is_vps(char arr[]) {
	stack a;
	node* tmp;
	a.count = 0;
	a.top = NULL;
	int i = 0;
	
	for (i = 0; arr[i]; i++) {
		if (arr[i] == '(') {
			tmp = (node *)malloc(sizeof(node));
			if (a.count == 0) {
				a.top = tmp;
				tmp->next = NULL;
			}
			else {
				tmp->next = a.top;
				a.top = tmp;
			}
			a.count++;
		}
		else {
			if (a.count == 0) {
				printf("NO\n");
				return;
			}
			tmp = a.top;
			if (a.count != 1)
				a.top = a.top->next;
			else
				a.top = NULL;
			a.count--;

			free(tmp);
		}

	}
	if (a.count != 0) {
		printf("NO\n");
	}
	else {
		printf("YES\n");
	}
}

int main() {
	int num;
	scanf("%d", &num);
	char **arr;
	arr = (char **)malloc(sizeof(char *)*num);
	for (int i = 0; i < num; i++) {
		arr[i] = (char *)malloc(sizeof(char) * 51);
		scanf("%s", arr[i]);
	}
	for (int i = 0; i < num; i++) {
		is_vps(arr[i]);
	}

}
