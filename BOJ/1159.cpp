#include<iostream>
#include<string>
using namespace std;
int arr[26];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		arr[a[0] - 'a']++;
	}
	bool five = false;
	for (int i = 0; i < 26; i++) {
		if (arr[i] >= 5) {
			five = true;
			printf("%c", 'a' + i);
		}
	}
	if (!five)
		printf("PREDAJA");
}