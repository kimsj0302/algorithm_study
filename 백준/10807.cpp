#include <algorithm>
#include <iostream>
#include<map>

using namespace std;

int main() {
	map <int, int> m;
	int N, M;
	scanf("%d", &N);
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		m[tmp]++;
	}
		scanf("%d", &tmp);
		printf("%d ", m[tmp]);
}

