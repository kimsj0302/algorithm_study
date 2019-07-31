#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;


int main() {
	int test_case;
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++) {
		int N, M;
		scanf("%d %d", &N, &M);
		long long X=0, Y=0;
		int n;
		for (int j = 0; j < M; j++) {
			scanf("%d", &n);
			X += pow(10, M - 1 - j)*n;
		}
		for (int j = 0; j < M; j++) {
			scanf("%d", &n);
			Y += pow(10, M - 1 - j)*n;
		}
		//printf("-%d-%d-", X, Y);
		vector <int> dol;
		int num;
		for (int j = 0; j < N; j++) {
			scanf("%d", &num);
			dol.push_back(num);
		}
		long long Z;
		int answer=0;
		for (int j = 0; j < N; j++) {
			Z = 0;
			for (int k = 0; k < M; k++) {
				Z += dol[(j + k) % N] * pow(10, M - 1 - k);
			}
			//printf("\n%d\n", Z);
			if (Z >= X && Y >= Z)
				answer++;
		}
		printf("%d\n", answer);
	}
}