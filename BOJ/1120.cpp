#include<iostream>
#include<string>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	if (b.length() < a.length()) {
		string tmp = a;
		a = b;
		b = tmp;
	}
	int min = 100000;
	for (int i = 0; i <= b.length() - a.length(); i++) {
		int sta;
		int stb = i;
		int diff = 0;
		for (int sta = 0; sta < a.length(); sta++, stb++) {
			if (a[sta] != b[stb])
				diff++;
			
		}
		if (min > diff)
			min = diff;
	}
	printf("%d", min);
}