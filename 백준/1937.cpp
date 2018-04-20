#include <algorithm>
#include <iostream>
#include <cstring>
#include<string.h>
#include<vector>
#include <stdio.h>
#include <time.h>

#include<stack>
#include<queue>

using namespace std;
int panda[501][501];
int new_panda[501][501] = { 0, };

void DFS(int x, int y,int n) {
	if (x > 0 && new_panda[x - 1][y] == 0 && panda[x][y] < panda[x - 1][y]) {
		DFS(x - 1, y, n);
	}
	if (y > 0 && new_panda[x][y-1] == 0 && panda[x][y] < panda[x][y-1]) {
		DFS(x, y - 1, n);
	}
	if (x < n-1 && new_panda[x + 1][y] == 0 && panda[x][y] < panda[x + 1][y]) {
		DFS(x + 1, y, n);
	}
	if (y < n - 1 && new_panda[x][y+1] == 0 && panda[x][y] < panda[x][y+1]) {
		DFS(x, y + 1, n);
	}
	int max_around=0;
	if (x > 0 && new_panda[x - 1][y] > max_around && panda[x][y] < panda[x - 1][y])
		max_around = new_panda[x - 1][y];
	if (y > 0 && new_panda[x][y - 1] > max_around && panda[x][y] < panda[x][y - 1])
		max_around = new_panda[x][y - 1];
	if (x < n - 1 && new_panda[x + 1][y] > max_around && panda[x][y] < panda[x+1][y])
		max_around = new_panda[x + 1][y];
	if (y < n - 1 && new_panda[x][y + 1] > max_around && panda[x][y] < panda[x ][y + 1])
		max_around = new_panda[x][y + 1];
	new_panda[x][y] = max_around+1;
}
int main() {
	
	vector <int> arr;
	int n;
	int number;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &number);
			panda[j][i] = number;
			arr.push_back(number);
		}
	}
	sort(arr.begin(), arr.end());
	int sort_num = 0;
	int max = 0;
	int st_x, st_y;
	int zero_num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (new_panda[i][j] != 0)
				continue;
			else {
				DFS(i, j, n);
				if (new_panda[i][j] > max)
					max = new_panda[i][j];
			}

		}
	}
	printf("%d", max);
}
	