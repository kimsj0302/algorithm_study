#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N, L;
	int tmp;
	vector<int> leak;
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		leak.push_back(tmp);
	}
	sort(leak.begin(), leak.end());
	int place = 0;
	int ans = 0;
	while (place < leak.size()) {
		int i;
		for (i = place+1; i<leak.size() && leak[i] < leak[place] + L ; i++);
		place = i;
		ans++;
	}
	printf("%d", ans);
}