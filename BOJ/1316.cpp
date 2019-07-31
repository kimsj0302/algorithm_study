#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		int count[26];
		for (int j = 0; j < 26; j++)
			count[j] = 0;
		bool isword = true;
		for (int j = 0; j < a.size(); j++) {
			if(count[a[j]-'a']==0)
				count[a[j] - 'a']++;
			else {
				if (a[j - 1] - 'a' != a[j] - 'a')
					isword = false;
			}
		}
		if (isword)
			sum++;
	}
	printf("%d", sum);
}