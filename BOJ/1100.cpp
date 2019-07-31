#include<iostream>
using namespace std;

int board[8][8] = { {1,0,1,0,1,0,1,0},{ 0,1,0,1,0,1,0,1 },{ 1,0,1,0,1,0,1,0 } ,{ 0,1,0,1,0,1,0,1 },{ 1,0,1,0,1,0,1,0 } ,{ 0,1,0,1,0,1,0,1 },{ 1,0,1,0,1,0,1,0 },{ 0,1,0,1,0,1,0,1 } };
int main() {
	int n = 8;
	int sum=0;
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			char tmp;
			scanf("%c", &tmp);
			if (tmp == '\n')
				scanf("%c", &tmp);
			if (tmp == 'F')
				sum += board[i][j];
		}
	printf("%d", sum);
}