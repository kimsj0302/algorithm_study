#include<iostream>
using namespace std;
char arr[51][51];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++) {
			char tmp;
			scanf("%c", &tmp);
			if (tmp == '\n') {
				scanf("%c", &tmp);

			}
			arr[i][j] = tmp;
		}

	int max = 1;
	for (int i = 0; i<n; i++)
		for (int j = 0; j < m; j++) {
			char here = arr[i][j];
			for (int k = i; k < n; k++) {
				if (arr[k][j] == here) {
					for (int l = j; l < m; l++) {
						if (arr[i][l] == here) {
							if (arr[k][l] == here) {
								if (max < (k - i+1)*(1+l - j) && (k - i ) == (l - j))
									max = (k - i+1)*(1+l - j);
							}
						}
					}
				}
			}
		}
	printf("%d\n", max);
}