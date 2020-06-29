#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> vec;
void cal(int n,string a) {
	string tmp = a;
	if (n == 1) {
		vec.push_back(tmp + "1");
	}
	else if (n == 2) {
		vec.push_back(tmp + "2");
		cal(n - 1, tmp + "1+");
	}
	else if (n == 3) {
		vec.push_back(tmp + "3");
		cal(n - 1, tmp + "1+");
		cal(n - 2, tmp + "2+");
	}
	else {
		cal(n - 1, tmp + "1+");
		cal(n - 2, tmp + "2+");
		cal(n - 3, tmp + "3+");
	}
}
int main() {
	int n,k;
	cin >> n >> k;
	cal(n,"");
	sort(vec.begin(), vec.end());
	if (vec.size() < k) cout << "-1" << endl;
	else	cout << vec[k - 1] << endl;
}