#include<iostream>
#include<vector>
using namespace std;

void prin(int n, bool visit[9],vector<int> arr) {
	bool com = true;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			com = false;
			visit[i] = true;
			arr.push_back(i);
			prin(n, visit, arr);
			arr.pop_back();
			visit[i] = false;

		}
	}
	if (com) {
		for (int i = 0; i < arr.size(); i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
}


int main() {
	bool visit[9] = { false,false ,false ,false ,false,false,false ,false ,false };
	int n;
	vector<int> arr;
	scanf("%d", &n);
	prin(n, visit,arr);
}