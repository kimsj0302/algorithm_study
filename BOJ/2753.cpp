#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	bool t = (n % 400 == 0) || ((n % 100 != 0) && (n % 4 == 0));
	printf("%d\n", t);
}