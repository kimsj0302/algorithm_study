
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STRING 20

// 큐 노드 구조체 NODE 선언
typedef struct node
{
	char data;
	int target;
	struct node *next;
} NODE;

// 큐 헤드 구조체 QUEUE 선언
typedef struct
{
	int count;
	NODE *front;
	NODE *rear;
} QUEUE;

void printQueue(QUEUE *q);
int enqueue(QUEUE *q, char data);
int dequeue(QUEUE *q, char *data);
int isEmpty(QUEUE *q);

int main()
{
	QUEUE *queue;
	NODE* tmp;
	int testcasenum, N, M,i,j,num,count,istarget;
	scanf("%d", &testcasenum);
	queue = (QUEUE*)malloc(sizeof(QUEUE)*testcasenum);
	for (i = 0; i < testcasenum; i++) {
		scanf("%d %d", &N, &M);
		queue[i].count = 0;
		queue[i].front = NULL;
		queue[i].rear = NULL;
		for (j = 0; j < N; j++) {
			scanf("%d", &num);
			enqueue(&queue[i], num);
			if (M == j) {
				queue[i].rear->target = 1;
			}
		}
	}
	for (i = 0; i < testcasenum; i++) {
		count = 0;
		num = queue[i].front->data;
		for (tmp = queue[i].front; ; tmp=tmp->next) {
			if (tmp == NULL) {
				if (queue[i].front->target) {
					printf("%d\n", count+1);
					break;
				}
				dequeue(&queue[i], &num);
				num = queue[i].front->data;
				tmp = queue[i].front;
				count++;
				continue;
			}
			if (num < (tmp->data)) {
				istarget = 0;
				if (queue[i].front->target)
					istarget = 1;
				dequeue(&queue[i], &num);
				enqueue(&queue[i], num);
				num = queue[i].front->data;
				tmp = queue[i].front;
				if (istarget == 1) {
					queue[i].rear->target = 1;
				}
			}
			
		}
		
	}

} // main

void printQueue(QUEUE *q)
{
	char data;

	printf("   ");
	while (dequeue(q, &data)) // 큐가 빌 때까지 dequeue 함수 호출
		printf("%c", data);



	printf("\n\n");
} // printQueue

  // enqueue 성공시 1, 실패시 0
int enqueue(QUEUE *q, char data)
{

	NODE *tmp;

	// 큐 노드 생성
	tmp = (NODE *)malloc(sizeof(NODE));
	if (!tmp) // 동적 할당 실패시
		return 0;

	// 생성한 노드에 값 설정
	tmp->data = data;
	tmp->next = NULL;
	tmp->target = 0;


	if (isEmpty(q)) // 큐가 비어 있는 경우(isEmpty 함수 호출)
	{

		//비어있음.

		q->front = tmp;
		q->rear = tmp;

	}
	else
	{
		q->rear->next = tmp;
		q->rear = tmp;

	}

	q->count++;

	return 1;
} // enqueue

  // dequeue 성공시 1, 실패시 0
int dequeue(QUEUE *q, char *data)
{
	NODE *tmp;

	if (isEmpty(q)) // 큐가 비어 있는 경우
		return 0;
	else {
		tmp = (NODE*)malloc(sizeof(NODE));
		*data = q->front->data;
		tmp = q->front;
		q->front = tmp->next;
		q->count--;
		free(tmp);
		if (q->count == 0)
			q->rear = NULL;
		return 1;
	}



} // dequeue

  // 큐가 비어 있으면 1, 그렇지 않으면 0을 반환
int isEmpty(QUEUE *q)
{
	return q->rear == NULL;
}
