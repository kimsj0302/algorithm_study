#include <algorithm>
#include <iostream>
#include<vector>
using namespace std;
int moun[1001][1001];
int DP[1001][1001] = { 0, };
int W, H;
void DFS(int x, int y) {
	if (x > 0 && DP[x - 1][y] == 0 && moun[x][y] < moun[x - 1][y]) {
		DFS(x - 1, y);
	}
	if (y > 0 && DP[x][y - 1] == 0 && moun[x][y] < moun[x][y - 1]) {
		DFS(x, y - 1);
	}
	if (x < H - 1 && DP[x + 1][y] == 0 && moun[x][y] < moun[x + 1][y]) {
		DFS(x + 1, y);
	}
	if (y < W - 1 && DP[x][y + 1] == 0 && moun[x][y] < moun[x][y + 1]) {
		DFS(x, y + 1);
	}
	int max_around = 0;
	if (x > 0 && DP[x - 1][y] > max_around && moun[x][y] < moun[x - 1][y])
		max_around = DP[x - 1][y];
	if (y > 0 && DP[x][y - 1] > max_around && moun[x][y] < moun[x][y - 1])
		max_around = DP[x][y - 1];
	if (x < H - 1 && DP[x + 1][y] > max_around && moun[x][y] < moun[x + 1][y])
		max_around = DP[x + 1][y];
	if (y < W - 1 && DP[x][y + 1] > max_around && moun[x][y] < moun[x][y + 1])
		max_around = DP[x][y + 1];
	DP[x][y] = max_around + 1;
}


int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d", &H, &W);
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				int tmp;
				scanf("%d", &tmp);
				moun[i][j] = tmp;
				DP[i][j] = 0;
			}
		}
		int max = -1;
		int indx, indy;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (DP[i][j] != 0)
					continue;
				else {
					DFS(i, j);
					if (DP[i][j] > max) {
						max = DP[i][j];
						indx = i;
						indy = j;
					}
					else if(DP[i][j]==max && moun[indx][indy]>moun[i][j]){
						indx = i;
						indy = j;
					}
				}

			}
		}
		printf("%d\n", max);

		printf("%d ", moun[indx][indy]);
		for (int i = max-1; i >0; i--) {
			vector < pair<int, pair<int, int> > > tmp;
			if (indx > 0 && DP[indx-1][indy]==i && moun[indx][indy] < moun[indx - 1][indy]) {
				tmp.push_back(make_pair(moun[indx - 1][indy], make_pair(indx - 1, indy)));
			}
			if (indy > 0 && DP[indx][indy - 1] == i && moun[indx][indy] < moun[indx][indy - 1]) {
				tmp.push_back(make_pair(moun[indx][indy - 1], make_pair(indx, indy - 1)));
			}
			if (indx < H - 1 && DP[indx + 1][indy] == i && moun[indx][indy] < moun[indx + 1][indy]) {
				tmp.push_back(make_pair(moun[indx + 1][indy], make_pair(indx + 1, indy)));
			}
			if (indy < W - 1 && DP[indx][indy + 1] == i && moun[indx][indy] < moun[indx][indy + 1]) {
				tmp.push_back(make_pair(moun[indx][indy + 1], make_pair(indx, indy + 1)));
			}
			sort(tmp.begin(), tmp.end());
			indx = tmp[0].second.first;
			indy = tmp[0].second.second;
			printf("%d ", moun[indx][indy]);
		}
		printf("\n");
	}
}
