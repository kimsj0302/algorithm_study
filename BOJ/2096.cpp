#include<iostream>
#include<algorithm>
using namespace std;
int ma[3];
int mi[3];
int main() {
	int n;
	scanf("%d", &n);
	scanf("%d%d%d", &ma[0], &ma[1], &ma[2]);
	mi[0] = ma[0];
	mi[1] = ma[1];
	mi[2] = ma[2];
	for (int i = 1; i < n; i++) {
		int i1, i2, i3;
		scanf("%d%d%d", &i1, &i2, &i3);
		int m1, m2, m3;
		m1 = max(ma[0], ma[1])+i1;
		m2 = max(max(ma[0], ma[1]), ma[2]) + i2;
		m3 = max(ma[1], ma[2]) + i3;
		ma[0] = m1;
		ma[1] = m2;
		ma[2] = m3;
		m1 = min(mi[0], mi[1])+i1;
		m2 = min(min(mi[0], mi[1]), mi[2]) + i2;
		m3 = min(mi[1], mi[2]) + i3;
		mi[0] = m1;
		mi[1] = m2;
		mi[2] = m3;
		//printf("%d %d %d %d %d %d\n", ma[0], ma[1], ma[2], mi[0], mi[1], mi[2]);
	}
	printf("%d %d\n", max(ma[0], max(ma[1], ma[2])), min(mi[0], min(mi[1], mi[2])));
}