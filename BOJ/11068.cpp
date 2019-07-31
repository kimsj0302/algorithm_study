#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
using namespace std;


int is_right(vector<int> numberlist,int length) {
	int i;
	for (i = 0; i < length / 2; i++) {
		if (numberlist[i] != numberlist[length - 1 - i])
			return 0;
	}
	return 1;
}

vector <vector<int> > num(65);
int length[65] = { 0, };
int main() {
	
	int cases;
	int case_num;
	int answer;
	int tmp;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		answer = 0;
		
		scanf("%d", &case_num);
		for (int j = 2; j < 65; j++) {
			tmp = case_num;
			length[j] = 0;
			num[j].clear();
			for (int k = 0; tmp ; k++) {
				num[j].push_back(tmp%j);
				tmp = tmp / j;
				length[j]++;
			}
			if (is_right(num[j], length[j]) == 1) {
				//printf("=%d=", j);
				answer = 1;
				length[j] = 0;
				break;
			}
		}
		printf("%d\n", answer);

	}
}