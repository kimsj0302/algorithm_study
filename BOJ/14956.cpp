#include<iostream>
using namespace std;


pair<int, int> divide(int step,int size) {
	if (size == 1)
		return make_pair(1, 1);
	int hole = (size * size) / 4;
	pair<int, int> dir;
	if (step <= hole) {
		dir = divide(step, size / 2);
		return make_pair(dir.second, dir.first);
	}
	else if (step <= 2 * hole) {
		dir = divide(step - hole, size / 2);
		dir.second += size / 2;
		return dir;
	}
	else if (step <= 3 * hole) {
		dir = divide(step - 2 * hole, size / 2);
		dir.first += size / 2;
		dir.second += size / 2;
		return dir;
	}
	else {
		dir = divide(step - 3 * hole, size / 2);
		int x = dir.first, y = dir.second;
		return make_pair(1 + size - y,1 + size/2 - x );
	}
}


int main() {
	int size, step;
	scanf("%d%d", &size, &step);
	pair<int, int> ans;

	ans = divide(step,size);
	printf("%d %d\n", ans.first, ans.second);
}