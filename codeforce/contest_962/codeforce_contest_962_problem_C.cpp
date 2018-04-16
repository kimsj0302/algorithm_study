#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int a;
int cal(int b) {
	int tmp = sqrt((double)b);
	if (b == 0)
		return -1;
	if (b < 10) {
		if (b==1 || b == 4 || b == 9)
			return 1;
		else
			return -1;
	}
	if (tmp*tmp == b)
		return (int)log10((double)b) + 1;
	int tmp1, tmp2;
	tmp1 = b;
	tmp2 = 0;
	int max = -1;
	bool minus = false;
	int inc = 0;
	while (tmp1 != 0) {
		int send;
		send = (tmp1 / 10)*pow((double)10,(double)inc)+ tmp2;
		tmp2 += (tmp1 % 10)*pow((double)10,(double)inc);
		tmp1 /= 10;
		inc++;
		int t=cal(send);
		if (t > max)
			max = t;
	}
	printf("[%d %d]\n", b, max);
	return max;
}
int main() {
	
	scanf("%d", &a);
	int tmp = cal(a);
	if (tmp == -1)
		printf("-1");
	else
		printf("%d", (int)log10((double)a) + 1 - tmp);
}