#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<fstream>

using namespace std;


int arr[25][25] = { 0, };


int main() {
	int size;
	vector<int> answer;
	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		char tmp[25];
		scanf("%s", tmp);
		for (int j = 0; j < size; j++) {
			arr[i][j] = -(tmp[j]-48);
		}

	}
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			if (arr[i][j] == -1) {
				queue<pair<int, int> > que;
				int gone[25][25] = { 0, };
				int ans_tmp=1;
				int now_x = i, now_y = j;
				gone[now_x][now_y] = 1;
				do {

					if (!que.empty()) {
						now_x = que.front().first;
						now_y = que.front().second;

						que.pop();
					}
					if (now_x > 0 && gone[now_x - 1][now_y] == 0 && arr[now_x - 1][now_y] == -1) {
						arr[now_x - 1][now_y] = answer.size() + 1;
						gone[now_x - 1][now_y] = 1;
						ans_tmp++;
						que.push(make_pair(now_x - 1, now_y));
					}
					if (now_y > 0 && gone[now_x][now_y - 1] == 0 && arr[now_x][now_y - 1] == -1) {
						arr[now_x][now_y - 1] = answer.size() + 1;
						gone[now_x ][now_y - 1] = 1;
						ans_tmp++;
						que.push(make_pair(now_x , now_y- 1));
					}
					if (now_x < 24 && gone[now_x + 1][now_y] == 0 && arr[now_x + 1][now_y] == -1) {
						arr[now_x + 1][now_y] = answer.size() + 1;
						gone[now_x + 1][now_y] = 1;
						ans_tmp++;
						que.push(make_pair(now_x + 1, now_y));
					}
					if (now_y < 24 && gone[now_x][now_y + 1] == 0 && arr[now_x][now_y + 1] == -1) {
						arr[now_x][now_y + 1] = answer.size() + 1;
						gone[now_x ][now_y + 1] = 1;
						ans_tmp++;
						que.push(make_pair(now_x, now_y + 1));
					}


				} while (!que.empty());
				if(ans_tmp!=0)
					answer.push_back(ans_tmp);
			}
		}

	printf("%d\n", answer.size());
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		printf("%d\n", answer[i]);
	}
}