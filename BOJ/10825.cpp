#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	char tmp[11];
	
	vector <pair<int,pair<int, pair<int, string> > > >  a;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int q, w, e;
		scanf("%11s %d %d %d", tmp, &q, &w, &e);
		string r = tmp;
		a.push_back(make_pair(-q, make_pair(w,  make_pair(-e, r)  )));
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		printf("%s\n", a[i].second.second.second.c_str());
	}
}