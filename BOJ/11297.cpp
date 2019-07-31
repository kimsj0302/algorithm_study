#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	priority_queue<int> Q;
	int n;
	scanf("%d", &n);
	int order;
	for (int i = 0; i < n; i++) {
		scanf("%d", &order);
		if (order == 0) {
			if (Q.empty()) {
				printf("0\n");
			}
			else {
				printf("%d\n", Q.top());
				Q.pop();
			}
		}
		else {
			Q.push(order);
		}
	}
}