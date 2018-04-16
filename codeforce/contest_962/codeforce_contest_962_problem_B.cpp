#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int num, a, b;
	int answer = 0;
	int total=0;
	scanf("%d %d %d", &num, &a, &b);
	char tmp;
	vector<int> arr;
	int seat = 0;
	getchar();
	for (int i = 0; i < num; i++) {
		char a;
		scanf("%c", &a);
		if (a == '.')
			total++;
		if(a!='*'){
			seat++;
		}
		else {
			if(seat!=0)
				arr.push_back(seat);
			seat = 0;
		}
	}
	total = min(total, a + b);
	if (seat != 0)
		arr.push_back(seat);
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == 0)
			continue;
		int _tmp = arr[i];
		if (a == 0 && b == 0)
			break;
		if (a == 0) {
			if (b - (_tmp - _tmp / 2)>=0) {
				b -= (_tmp - _tmp / 2);
				answer += (_tmp - _tmp / 2);
				continue;
			}
		}
		if (b == 0) {
			if (a - (_tmp - _tmp / 2) >= 0) {
				a -= (_tmp - _tmp / 2);
				answer += (_tmp - _tmp / 2);
				continue;
			}
		}
		if (a > b) {
			if ((b - _tmp / 2 < 0) || (a - (_tmp - _tmp / 2) < 0)) {
				answer += min(b, _tmp / 2);
				
				answer += min(a, _tmp - _tmp / 2);
				if (b - _tmp / 2 < 0) {
					b = 0;
				}
				if (a - (_tmp - _tmp / 2) < 0) {
					a = 0;
				}
				continue;
			}
			b -= _tmp / 2;
			a -= (_tmp - _tmp / 2);
		}
		else{
			if ((a - _tmp / 2 < 0) || (b - (_tmp - _tmp / 2) < 0)) {
				answer += min(a, _tmp / 2);
				answer += min(b, _tmp - _tmp / 2);
				if (a - _tmp / 2 < 0) {
					a = 0;
				}
				if (b - (_tmp - _tmp / 2) < 0) {
					b = 0;
				}
				continue;
			}
			a -= _tmp / 2;
			b -= (_tmp - _tmp / 2);
		}
		answer += _tmp;
	}
	printf("%d", min(total,answer));
}