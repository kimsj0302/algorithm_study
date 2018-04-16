#include<iostream>

using namespace std;


int arr[1001][1001];
int w, h;

void arrdelete(int x, int y) {
	if (x < 0 || x >= w || y < 0 || y >= h)
		return;
	if (arr[x][y] == 1)
		arr[x][y] = 0;
	else
		return;
	arrdelete(x + 1, y);
	arrdelete(x + 1, y + 1);
	arrdelete(x + 1, y - 1);
	arrdelete(x, y + 1);
	arrdelete(x, y - 1);
	arrdelete(x - 1, y);
	arrdelete(x - 1, y + 1);
	arrdelete(x - 1, y - 1);
}
int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int answer = 0;
		scanf("%d %d", &w, &h);
		for(int j=0;j<w;j++)
			for (int k = 0; k < h; k++) {
				int tmp;
				scanf("%d", &tmp);
				arr[j][k] = tmp;
			}
		for (int j = 0; j<w; j++)
			for (int k = 0; k < h; k++) {
				if (arr[j][k] == 1) {
					answer++;
					arrdelete(j, k);
				}
			}
		printf("%d\n", answer);
	}
	
}