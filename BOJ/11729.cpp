#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>

using namespace std;

vector<pair<int, int> > k;
int qwer = 0;
void hanoi(int n,int st,int mid,int nd) {
	if (n == 1) {
		k.push_back(make_pair(st, nd));
		qwer++;
		return;
	}
	hanoi(n - 1, st,nd,mid);
	k.push_back(make_pair(st, nd));
	qwer++;
	hanoi(n - 1, mid,st,nd);

}
int main() {
	int n;
	scanf("%d",&n);
	hanoi(n, 1, 2, 3);
	printf("%d\n", qwer);
	for (int i = 0; i < k.size(); i++) {
		printf("%d %d\n", k[i].first, k[i].second);
	}
}