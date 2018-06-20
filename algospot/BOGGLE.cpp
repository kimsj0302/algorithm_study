#include<iostream>
#include<string>
using namespace std;

char board[5][5];
int DP[5][5][11];
string word;
int hasWord(int x, int y, int num) {
	if (DP[x][y][num] != 0)
		return DP[x][y][num];
	if (num == word.size()-1)
		return DP[x][y][num] = 1;
	if (x > 0 && board[x - 1][y] == word[num + 1])
		if (hasWord(x - 1, y, num + 1)==1)
			return DP[x][y][num] = 1;
	if (y > 0 && board[x][y - 1] == word[num + 1])
		if (hasWord(x, y - 1, num + 1)==1)
			return DP[x][y][num] = 1;
	if (x < 4 && board[x + 1][y] == word[num + 1])
		if (hasWord(x + 1, y, num + 1) == 1)
			return DP[x][y][num] = 1;
	if (y < 4 && board[x][y + 1] == word[num + 1])
		if (hasWord(x, y + 1, num + 1) == 1)
			return DP[x][y][num] = 1;
	if (x>0 && y > 0 && board[x - 1][y - 1] == word[num + 1])
		if (hasWord(x - 1, y - 1, num + 1) == 1)
			return DP[x][y][num] = 1;
	if (x>0 && y < 4 && board[x - 1][y + 1] == word[num + 1])
		if (hasWord(x - 1, y + 1, num + 1) == 1)
			return DP[x][y][num] = 1;
	if (x < 4 && y > 0 && board[x + 1][y - 1] == word[num + 1])
		if (hasWord(x + 1, y - 1, num + 1) == 1)
			return DP[x][y][num] = 1;
	if (x < 4 && y < 4 && board[x + 1][y + 1] == word[num + 1])
		if (hasWord(x + 1, y + 1, num + 1) == 1)
			return DP[x][y][num] = 1;
	return DP[x][y][num] = -1;

}

int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j<5; j++)
			for (int k = 0; k < 5; k++) {
				cin >> board[j][k];
			}
		int case_num;
		scanf("%d", &case_num);
		for (int j = 0; j < case_num; j++) {
			for (int q = 0; q < 5; q++)
				for (int w = 0; w < 5; w++)
					for (int e = 0; e < 11; e++)
						DP[q][w][e] = 0;
			cin >> word;
			bool answer = false;

			for (int l = 0; l<5; l++)
				for (int k = 0; k < 5; k++) {
					if (board[l][k]==word[0]&& hasWord(l, k, 0)==1)
						answer = true;
				}
			if (answer)
				cout << word << " " << "YES" << endl;
			else
				cout << word << " " << "NO" << endl;
		}
	}
}