#include <algorithm>
#include <iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

int main() {
	map <string, int> m;
	vector <string> vec;
	int NL, NH;
	scanf("%d %d", &NH, &NL);
	string a;
	getline(cin, a);
	for (int i = 0; i < NH; i++) {
		getline(cin, a);
		m[a]++;
	}
	for (int i = 0; i < NL; i++) {
		getline(cin, a);
		if (m[a] != 0)
			vec.push_back(a);
	}
	printf("%d\n", vec.size());
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
}

