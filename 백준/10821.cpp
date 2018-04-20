#include <algorithm>
#include <iostream>
#include<string>

using namespace std;

int main() {
	string a;
	getline(cin, a);
	int answer = 1;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == ',')
			answer++;
	}
	printf("%d", answer);
}

