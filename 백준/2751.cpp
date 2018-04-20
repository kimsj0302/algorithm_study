#include <algorithm>
#include <iostream>
#include <cstring>
#include<string.h>
#include<vector>
#include <stdio.h>
#include <time.h>

#include<stack>
#include<queue>

using namespace std;

int main() {
	vector <int> rope;
	int n,num;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		rope.push_back(num);
	}
	sort(rope.begin(), rope.end());
	for(int i=0;i<n;i++){
			printf("%d\n", rope[i]);
		}
	
}
	