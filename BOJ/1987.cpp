#include <stdio.h>
#include <malloc.h>


typedef struct _node {
	int n;
	struct _node* next;
} node;

node *Shead;
int Scount;
int vertex, edge;
//push at front
void push(int x) {
	node* newNode = (node *)malloc(sizeof(node));
	newNode->n = x;
	newNode->next = NULL;

	newNode->next = Shead;
	Shead = newNode;
	Scount++;
}

//pop from front
int pop(void) {
	node* tmp = Shead;
	int x = tmp->n;

	Shead = Shead->next;
	Scount--;

	free(tmp);
	return x;
}

int check(char ch, char serch[]) {
	for (int i = 0; serch[i]; i++) {
		if (ch == serch[i])
			return 1;
	}
	return 0;
}

void DFS(int x,int y,char serch[],char list[][21],int i,int *answer) {
	if (check(list[x][y], serch))
		return;
	serch[i] = list[x][y];
	if (i > *answer)
		*answer = i;
	if (x > 0)
		DFS(x - 1, y, serch, list, i + 1, answer);
	if (y > 0)
		DFS(x, y-1, serch, list, i + 1, answer);
	if (x < vertex-1)
		DFS(x +1, y, serch, list, i + 1, answer);
	if (y  < edge - 1)
		DFS(x, y + 1, serch, list, i + 1, answer);
	serch[i] = 0;

}

int main(void) {
	int a, b;
	
	char ch;
	char list[21][21] = { 0, };
	char serch[27] = { 0, };
	int answer=0,i,j;
	scanf("%d %d ", &vertex, &edge);
	for (i = 0; i < vertex; i++) {
		for (j = 0; j < edge; j++) {
			do {
				scanf("%c", &ch);
			} while (ch == '\n');
			list[i][j] = ch;
		}
	}

	//DFS
	DFS(0, 0, serch, list, 0, &answer);
	printf("%d", answer+1);
}