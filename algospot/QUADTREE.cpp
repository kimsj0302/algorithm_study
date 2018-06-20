#include<iostream>
#include<string>
using namespace std;


void auqd(int st, int nd,string &nomal) {
	if (nomal[st]!='x') {
		cout << nomal[st];
		return;
	}
	cout << "x";
	int tmp = st+1;
	int LU, LD, RU;
	for (LU = tmp; LU <= tmp; LU++) {
		if (nomal[LU] == 'x')
			tmp += 4;
	}
	LU--;
	tmp++;
	for (RU = tmp; RU <= tmp; RU++) {
		if (nomal[RU] == 'x')
			tmp += 4;
	}
	RU--;
	tmp++;
	for (LD = tmp; LD <= tmp; LD++) {
		if (nomal[LD] == 'x')
			tmp += 4;
	}
	LD--;
	auqd(RU+1, LD, nomal);
	auqd(LD+1, nd, nomal);
	auqd(st + 1, LU, nomal);
	auqd(LU+1, RU,nomal);
}



int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {

		string nomal;
		cin >> nomal;
		auqd(0, nomal.size() - 1,nomal);
		cout << endl;
	}
}