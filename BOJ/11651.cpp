#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	//char tmp[20001];
	
	vector < pair<int, int> >   a;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		//scanf("%20001s", tmp);
		//string r = tmp;
		int t, y;
		scanf("%d %d", &t, &y);
		a.push_back(make_pair(y,t));
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", a[i].second, a[i].first);
	}
}