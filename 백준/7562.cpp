#include<iostream>
#include<queue>
using namespace std;

struct ele{
	int x;
	int y;
	int num;
	ele(int a, int b, int c) : x(a), y(b), num(c) {};
};

int x[8] = {1,1,2,2,-1,-1,-2,-2};
int y[8] = {2,-2,1,-1,2,-2,1,-1};

int main() {
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		int l;
		scanf("%d", &l);
		int stx, sty, ndx, ndy;
		scanf("%d %d %d %d", &stx, &sty, &ndx, &ndy);
		int arr[301][301] = { 0, };
		queue<struct ele> que;
		struct ele first(stx, sty, 0);
		que.push(first);
		while (!que.empty()) {
			struct ele loc = que.front();
			que.pop();
			if (loc.x == ndx &&  loc.y == ndy)
				break;
			for (int j = 0; j < 8 ; j++) {
				if (loc.x + x[j] >= 0 && loc.x + x[j] < l && loc.y + y[j] >= 0 && loc.y + y[j] < l && arr[loc.x + x[j]][loc.y + y[j]] == 0) {
					struct ele tmp(loc.x + x[j], loc.y + y[j], loc.num + 1);
					que.push(tmp);
					arr[loc.x+x[j]][loc.y+y[j]] = loc.num+1;
				}
			}
		}
		printf("%d\n", arr[ndx][ndy]);
	}
}