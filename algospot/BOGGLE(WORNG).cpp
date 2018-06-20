#include<iostream>
#include<string>
using namespace std;

char board[5][5];
string word;
bool hasWord(int x, int y,int num) {
	if (num == word.size())
		return true;
	if (num > word.size() || word[num]!=board[x][y])
		return false;

	if (x > 0 && board[x - 1][y] == word[num + 1])
		if (hasWord(x - 1, y, num + 1))
			return true;
	if (y > 0 && board[x][y-1] == word[num + 1])
		if (hasWord(x, y - 1, num + 1))
			return true;
	if (x < 4 && board[x + 1][y] == word[num + 1])
		if (hasWord(x + 1, y, num + 1))
			return true;
	if (y < 4 && board[x][y + 1] == word[num + 1])
		if (hasWord(x, y+1, num + 1))
			return true;
	if (x>0 && y > 0 && board[x - 1][y - 1] == word[num + 1])
		if (hasWord(x - 1, y - 1, num + 1))
			return true;
	if (x>0 && y < 4 && board[x - 1][y + 1] == word[num + 1])
		if (hasWord(x - 1, y + 1, num + 1))
			return true;
	if (x < 4 && y > 0 && board[x + 1][y - 1] == word[num + 1])
		if (hasWord(x + 1, y - 1, num + 1))
			return true;
	if (x < 4 && y < 4 && board[x + 1][y + 1] == word[num + 1])
		if (hasWord(x + 1, y + 1, num + 1))
			return true;
	return false;

}

int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		for(int j=0;j<5;j++)
			for (int k = 0; k < 5; k++) {
				cin >> board[j][k];
			}
		int case_num;
		scanf("%d", &case_num);
		for (int j = 0; j < case_num; j++) {
			cin >> word;
			bool answer = false;
			for (int l = 0; l<5; l++)
				for (int k = 0; k < 5; k++) {
					if (hasWord(l, k, 0))
						answer = true;
				}
			if (answer)
				cout << word << " " << "YES" << endl;
			else
				cout << word << " " << "NO" << endl;
		}
	}
}