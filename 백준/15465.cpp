#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct days {
	int day;
	string cow;
	int dif;
};
bool com1(days A, days B) {
	return A.day < B.day;
}
int main() {
	int d, di;
	string c;
	int n;
	vector<days> arr;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> d >> c >> di;
		days tmp = { d,c,di };
		arr.push_back(tmp);
	}
	int mil = 7, el = 7, be = 7;
	int now=7;
	int answer = 0;
	sort(arr.begin(), arr.end(),com1);
	for (int i = 0; i < n; i++) {
		if (arr[i].cow[0] == 'M') {
			mil += arr[i].dif;
		}
		else if (arr[i].cow[0] == 'E') {
			el += arr[i].dif;
		}
		else if (arr[i].cow[0] == 'B') {
			be += arr[i].dif;
		}
		int tmp = max(mil, max(el, be));
		int tmp_now = 0;
		if (mil == tmp)
			tmp_now += 1;
		if (el == tmp)
			tmp_now += 2;
		if (be == tmp)
			tmp_now += 4;
		if (tmp_now != now) {
			answer++;
			now = tmp_now;
		}
	}
	printf("%d\n", answer);

}