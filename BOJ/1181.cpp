#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	char tmp[20001];
	
	vector < pair<int, string> >   a;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%20001s", tmp);
		string r = tmp;
		a.push_back(make_pair(r.length(),r));
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		if(i>0 &&a[i].second != a[i-1].second)
			printf("%s\n", a[i].second.c_str());
		else if(i==0)
			printf("%s\n", a[i].second.c_str());
	}
}