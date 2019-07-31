#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int num;
	scanf("%d", &num);
	vector<int> red;
	vector<int> blue;
	vector<int> green;
	for (int i = 0; i < num; i++) {
		int r, b, g;
		scanf("%d %d %d", &r, &b, &g);
		red.push_back(r);
		blue.push_back(b);
		green.push_back(g);
	}
	for (int i = 1; i < num; i++) {
		red[i] += min(green[i - 1], blue[i - 1]);
		blue[i] += min(green[i - 1], red[i - 1]);
		green[i] += min(red[i - 1], blue[i - 1]);
	}
	printf("%d\n", min(min(red[num - 1], green[num - 1]), blue[num - 1]));

}