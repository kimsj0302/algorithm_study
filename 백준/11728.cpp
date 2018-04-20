#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>

using namespace std;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> a;
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		a.push_back(tmp);
	}
	vector<int> b;
	int num = 0;
	int i=0;
	while (num!=M || i!=N ) {
		int tmp;
		scanf("%d", &tmp);
		while (1) {
			if (i >= N) {
				if (num + i == M + N - 1) {
					printf("%d", tmp);
					return 0;
				}
				printf("%d ", tmp);
				num++;
				if (num<M)
					break;
			}
			else if (num >= M) {
				if (num + i == M + N - 1) {
					printf("%d", a[i++]);
					return 0;
				}
				printf("%d ", a[i++]);
			}
			else if (tmp < a[i]) {
				if (num + i == M + N - 1) {
					printf("%d", tmp);
					return 0;
				}
				printf("%d ", tmp);
				num++;
				if(num<M)
					break;
			}
			else {
				if (num + i == M + N - 1) {
					printf("%d", a[i++]);
					return 0;
				}
				printf("%d ", a[i++]);
			}
		}
	}
}