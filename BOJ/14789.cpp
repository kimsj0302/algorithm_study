#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<string>

using namespace std;

int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		string a;
		cin >> a;
		int l;
		scanf("%d", &l);
		int to_num = 0;
		//printf("%d", a.size());
		for (int j = 0; j <= a.size()-l; j++) {
			//printf("%c", a[j]);
			if (a[j] == '-') {
				to_num++;
				for (int k = j; k < j + l;k++) {
					//printf("[%c]", a[k]);
					if (a[k] == '-')
						a[k] = '+';
					else
						a[k] = '-';
				}
			}
		}
		bool po = true;
		for (int j = 1+a.size() - l; j < a.size(); j++) {
			if (a[j] == '-')
				po = false;
		}
		if (po == false) {
			printf("Case #%d: IMPOSSIBLE\n", i + 1);
		}
		else
			printf("Case #%d: %d\n", i + 1, to_num);
	}
}