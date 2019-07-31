#include <algorithm>
#include <iostream>
#include<vector>

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
	for(int i=n-1;i>=0;i--){
			printf("%d\n", rope[i]);
		}
	
}
	