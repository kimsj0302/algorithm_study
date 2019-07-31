#include<iostream>
#include<set>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	set <string> p_list;
	string name, p_where;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> name;
		cin >> p_where;
		if (p_where == "enter") {
			//printf("in");
			p_list.insert(name);
		}
		else {
			//printf("out");
			p_list.erase(name);
		}
	}
	set<string>::iterator iter;

	for (auto it = p_list.rbegin(); it != p_list.rend(); it++) {
		cout << *it << endl;
	}
}