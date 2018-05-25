#include<iostream>
#include<algorithm>
using namespace std;
int arr[201][201] = { 0, };
long long way[201][201] = { 0, };
int num;
int answer;
int main() {
	answer = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			int tmp;
			scanf("%d", &tmp);
			arr[i][j] = tmp;
		}
	}
	way[0][0] = 1;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (way[i][j] == 0 || (i == num - 1 && j == num - 1)) {
				continue;
			}
			int jump = arr[i][j];
			way[i + jump][j]+=way[i][j];
			way[i][j + jump]+=way[i][j];
		}
	}
	printf("%lld\n", way[num - 1][num - 1]);
}