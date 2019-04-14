#include<iostream>
using namespace std;

int cal_step(int size, int r, int c) {
	if (size == 1)
		return 0;
	if (r < size / 2 && c < size / 2)
		return cal_step(size / 2, r, c);
	else if (r < size / 2 && c >= size / 2)
		return (size / 2)*(size / 2) + cal_step(size / 2, r, c - size / 2);
	else if (r >= size / 2 && c < size / 2)
		return (size / 2)*(size / 2) * 2 + cal_step(size / 2, r-size/2, c);
	else
		return (size / 2)*(size / 2) * 3 + cal_step(size / 2, r - size / 2, c - size / 2);
}

int main() {
	int n, r, c;
	scanf("%d %d %d", &n, &r, &c);
	int size = 1;
	for(int i=0;i<n;i++){
		size *= 2;
	}
	printf("%d", cal_step(size, r, c));
}