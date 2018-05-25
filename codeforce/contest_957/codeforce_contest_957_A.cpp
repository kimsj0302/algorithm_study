#include<iostream>
#include<string>
using namespace std;
int main() {
	int num;
	string a;
	cin >> num;
	cin >> a;
	bool way2 = false;
	if (a[0] == '?')
		way2 = true;
	if (a[a.size() - 1] == '?')
		way2 = true;
	for (int i = 0; i < a.size() - 1; i++) {
		if (a[i] != '?'&& a[i] == a[i + 1]) {
			printf("No");
			return 0;
		}
		if (a[i] == '?' && a[i + 1] == '?')
			way2 = true;
		if (i < a.size() - 2 && a[i + 1] == '?' && a[i] == a[i + 2] && a[i] != '?')
			way2 = true;
	}
	if (way2)
		printf("Yes");
	else
		printf("No");

}