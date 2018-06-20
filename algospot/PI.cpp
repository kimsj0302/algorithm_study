#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int DP[10002] = { 0, };
string str;
int difficulty(string a) {
	if (a.size() < 3)
		while (1);
	char tmp = a[0];
	int i;
	for (i = 1; i < a.size(); i++) {
		if (a[i] != tmp)
			break;
	}
	if (i == a.size())
		return 1;
	int tmp2 = a[1] - a[0];
	for (i = 1; i < a.size() - 1; i++) {
		if (a[i + 1] - a[i] != tmp2)
			break;
	}
	if (i == a.size() - 1) {
		if (tmp2 == -1 || tmp2 == 1)
			return 2;
		else
			return 5;
	}
	char tmp3, tmp4;
	tmp3 = a[0], tmp4 = a[1];
	for (i = 2; i < a.size(); i++) {
		if (i % 2 == 0) {
			if (tmp3 != a[i])
				break;
		}
		else
			if (tmp4 != a[i])
				break;
	}
	if (i == a.size()) {
		return 4;
	}
	return 10;
}
int cal(int ind) {
	if (DP[ind] != 0)
		return DP[ind];
	int val = 987654321;
	int tmp;
	if (ind + 3 <= str.size()) {
		tmp = cal(ind + 3);
		val = min(val, tmp + difficulty(str.substr(ind, 3)));
	}
	if (ind + 4 <= str.size()) {
		tmp = cal(ind + 4);
		val = min(val, tmp + difficulty(str.substr(ind, 4)));
	}
	if (ind + 5 <= str.size()) {
		tmp = cal(ind + 5);
		val = min(val, tmp + difficulty(str.substr(ind, 5)));
	}
	return DP[ind] = val;

}
int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		cin >> str;
		memset(DP, 0, sizeof(DP));
		if (str.size() >= 3)
			DP[str.size() - 3] = difficulty(str.substr(str.size() - 3, 3));

		if (str.size() >= 4)
			DP[str.size() - 4] = difficulty(str.substr(str.size() - 4, 4));

		if (str.size() >= 5)
			DP[str.size() - 5] = difficulty(str.substr(str.size() - 5, 5));
		cout << cal(0) << endl;
	}
}