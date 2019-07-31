#include <algorithm>
#include <iostream>
#include<set>

using namespace std;

int main() {
	set <int> a;
	int N, M;
	scanf("%d", &N);
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		a.insert(tmp);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &tmp);
		printf("%d ", a.count(tmp));
	}
}
