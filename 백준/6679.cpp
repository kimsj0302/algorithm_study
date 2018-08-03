#include<iostream>

using namespace std;

int main() {
	for (int i = 1000; i < 10000; i++) {
		int _10=0, _12=0, _16=0;
		for (int j = i; j > 0; j /= 10) {
			_10 += j % 10;
		}
		for (int j = i; j > 0; j /= 12) {
			_12 += j % 12;
		}
		for (int j = i; j > 0; j /= 16) {
			_16 += j % 16;
		}
		if (_10 == _12 && _12 == _16)
			printf("%d\n", i);
	}
}