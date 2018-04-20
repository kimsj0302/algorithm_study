#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
void answer(int str,int end,int arr[]) {
	int i=1;
	int ans1, ans2;
	int place = 1;
	arr[0] = 1;
	if (str == 1)
		ans1 = 0;
	if (end == 1) {
		printf("1");
		return;
	}
	while(1) {
		i++;
		for (int j = 0; j < i; j++) {
			arr[place] = arr[place-1]+i;
			//printf("%d(place %d)  ", arr[place],place);
			place++; 
			if (place == str)
				ans1 = arr[place-2];
			if (place == end) {
				ans2 = arr[place-1];
				printf("%d", ans2 - ans1);
				return;
		}
		
		}
	}
}
int main(void) {
	int st, en;
	int arr[1005];
	scanf("%d %d", &st, &en);
	answer(st, en, arr);
}
