#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> P(100005, 0);
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int tmp;
		scanf("%d", &tmp);
		P[tmp]++;
	}
	for (int i = 0; i < 100001; i++) {
		if (P[i] == 0)
			continue;
		for (int j = 0; j < P[i]; j++) {
			printf("%d\n", i);
		}
	}
}