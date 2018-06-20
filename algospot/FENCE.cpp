#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(int L, int R,vector<int> &fence) {
	if (L == R) return fence[R];
	int mid = (L + R) / 2;
	int tmpmax = max(solve(L, mid, fence), solve(mid + 1, R, fence));
	int height = min(fence[mid], fence[mid + 1]);
	tmpmax = max(height * 2, tmpmax);
	int lo = mid, hi = mid + 1;
	while (L < lo || hi < R) {
		if (hi < R && (lo == L || fence[lo - 1] < fence[hi + 1])) {
			hi++;
			height = min(height, fence[hi]);
		}
		else {
			lo--;
			height = min(height, fence[lo]);
		}
		tmpmax = max(tmpmax, height*(hi - lo + 1));
	}
	return tmpmax;
}


int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int num2;
		scanf("%d", &num2);
		vector<int> fence;
		for (int j = 0; j < num2; j++) {
			int tmp;
			scanf("%d", &tmp);
			fence.push_back(tmp);
		}
		cout << solve(0, fence.size() - 1, fence)<<endl;
	}
}