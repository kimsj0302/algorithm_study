#include<iostream>
#include<map>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int t,p;
	cin >> t>>p;
	map<string, int> S1;
	map<int, string> S2;
	for(int i=1;i<=t;i++) {
		string str;
		cin >> str;
		S1[str] = i;
		S2[i] = str;
	}
	while (p--) {
		string str;
		cin >> str;
		if ('0' <= str[0] && str[0] <= '9') {
			printf("%s\n", S2[stoi(str)].c_str());
		}
		else {
			printf("%d\n", S1[str]);
		}
	}
}