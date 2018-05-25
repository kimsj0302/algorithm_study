#include<iostream>

using namespace std;

int cost[4] = { 50000,10000,5000,1000 };

int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int tmp;
		int answer = 0;
		scanf("%d", &tmp);
		answer += tmp / cost[0];
		tmp = tmp % cost[0];
		answer += tmp / cost[1];
		tmp = tmp % cost[1];
		answer += tmp / cost[2];
		tmp = tmp % cost[2];
		answer += tmp / cost[3];
		tmp = tmp % cost[3];
		printf("%d\n", answer);
	}
}