#include<stdio.h>
typedef struct _node {
	int x;
	int y;
	struct _node* next;
} node;

node *Qhead, *Qtail;
int Qcount;
//push at rear
void push(int x,int y) {
	//printf("push: (%d,%d)\n", x, y);
	node* newNode = (node *)malloc(sizeof(node));
	newNode->x = x;
	newNode->y = y;
	newNode->next = NULL;

	if (Qcount == 0) {
		Qhead = newNode;
		Qtail = newNode;
		Qcount++;
	}
	else {
		Qtail->next = newNode;
		Qtail = newNode;
		Qcount++;
	}
}

//pop from front
int pop(int *x,int *y) {
	node* tmp = Qhead;
	*x = tmp->x;
	*y = tmp->y;
	//printf("pop: (%d,%d)\n", *x, *y);
	if (Qcount == 1) {
		Qtail = NULL;
		Qhead = NULL;
		free(tmp);
		Qcount--;
	}
	else {
		Qhead = Qhead->next;
		Qcount--;
		free(tmp);
	}
	return;
}
int main() {
	int maze[101][101] = { 0 };
	int arr[1001] = { 0 };
	int i, j, N, M;
	int x=0, y=0;
	int num;
	char ch;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		for (j =0; j < M; j++) {
			do {
				scanf("%c", &ch);
			} while (ch == '\n');
			maze[i][j] = ch - '0';
		}
	}
	int count = 0,cnt=0;
	push(0, 0);
	maze[0][0] = 0;
	arr[1] = 1;
	while (Qcount != 0) {
		count++;
		while (arr[count] != 0) {
			pop(&x, &y);
			arr[count]--;
			if ((x<N-1&&y>=0) && maze[x + 1][y] == 1) {
				maze[x + 1][y] = 0;
				push(x + 1, y);

				if (x + 1 == N - 1 && y == M - 1) {
					printf("%d", count+1);
					return 0;
				}
				arr[count + 1]++;
			}
			if ((y<M-1&&x>=0) && maze[x][y + 1] == 1) {
				maze[x][y + 1] = 0;
				push(x, y + 1);
				if (x == N - 1 && y+1 == M - 1) {
					printf("%d", count+1);
					return 0;
				}
				arr[count + 1]++;
			}
			if ((x > 0&&y<M) && maze[x - 1][y] == 1) {
				maze[x - 1][y] = 0;
				push(x - 1, y);
				if (x - 1 == N - 1 && y == M - 1) {
					printf("%d", count+1);
					return 0;
				}
				arr[count + 1]++;
			}
			if (y > 0 && maze[x][y - 1] == 1) {
				maze[x][y - 1] = 0;
				push(x, y - 1);
				if (x == N - 1 && y-1 == M - 1) {
					printf("%d", count+1);
					return 0;
				}
				arr[count + 1]++;
			}
		}
	}
	
}