#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int arr[5001][5001] = { 0 };
int a1[5001], a2[5001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a1[i]);
	}
	for (int i = 0; i < n; i++) {
		a2[i] = a1[n - i - 1];
	}
	int i, j, a1l, a2l;
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++) {
			if (a1[i] == a2[j]) {
				if (i == 0 || j == 0)
					arr[i][j] = 1;
				else
					arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else {
				if (i == 0)
					arr[i][j] = arr[i][j - 1];
				else if (j == 0)
					arr[i][j] = arr[i - 1][j];
				else arr[i][j] = arr[i - 1][j] > arr[i][j - 1] ? arr[i - 1][j] : arr[i][j - 1];
			}
		}
	printf("%d\n", n - arr[i - 1][j - 1]);
}