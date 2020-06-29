#include<iostream>
using namespace std;
int main() {
	long long int a, b, v;
	cin >> a >> b >> v;
	if((v - a) % (a - b)==0)
		cout << (v - a) / (a - b) + 1 << endl;
	else
		cout << (v - a) / (a - b) + 2 << endl;

}