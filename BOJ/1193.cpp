#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	long long int n;
	cin >> n;
	int d;
	for (d = 1;; d++) {
		if (n <= d * (d + 1) / 2) break;
	}
	long long int nth = (d*(d + 1) / 2-n);
	if(d%2==0)
		cout << d-nth << "/" << 1+nth << endl;
	else
		cout << 1 + nth << "/" << d - nth << endl;

}