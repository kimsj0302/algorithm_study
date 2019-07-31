#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stack>
using namespace std;
pair<long long int, long long int> P[1000001];
bool cmp1(pair<long long int, long long int> a, pair<long long int, long long int>b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

bool cmp2(pair<long long int, long long int> a, pair<long long int, long long int>b) {
	long long int x1 = a.first - P[1].first;
	long long int y1 = a.second - P[1].second;
	long long int x2 = b.first - P[1].first;
	long long int y2 = b.second - P[1].second;
	if (atan2(x1, y1) == atan2(x2, y2)) {
		if (atan2(x1, y1)>0)
			return x1 < x2;
		else
			return y1 > y2;
	}
	return atan2(x1, y1) > atan2(x2, y2);
}
vector<int> st;

int ccw(int w1, int w2, int w3) {
	long long int s1 = (long long int)P[w1].first*P[w2].second + P[w2].first*P[w3].second + P[w3].first*P[w1].second;
	long long int s2 = (long long int)P[w2].first*P[w1].second + P[w3].first*P[w2].second + P[w1].first*P[w3].second;
	long long int s = s1 - s2;
	if (s >= 0) return 1;
	else return 0;
}
int main() {
	int a;
	long long int b, c;
	char d;
	scanf("%d", &a);
	int ind = 1;
	for (int i = 1; i <= a; i++) {
		scanf("%lld %lld", &b, &c);
		getchar();
		scanf("%c", &d);
		if (d != 'N') {
			P[ind] = make_pair(b, c);
			ind++;
		}
	}
	sort(P + 1, P + ind, cmp1);
	sort(P + 2, P + ind, cmp2);
	st.push_back(1);
	st.push_back(2);
	for (int i = 3; i < ind; i++) {
		while (1) {
			if (st.size() < 2)
				break;
			if (ccw(st[st.size() - 2], st[st.size() - 1], i) == 1) {
				break;
			}
			else {
				st.pop_back();
			}
		}
		st.push_back(i);
	}
	printf("%d\n", st.size());
	for (int i = 0; i < st.size(); i++) {
		printf("%lld %lld\n", P[st[i]].first, P[st[i]].second);
	}
}