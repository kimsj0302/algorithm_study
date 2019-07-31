#include<iostream>
#include<vector>
using namespace std;

int main() {
	while (1) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp == -1) break;
		int sum = 0;
		vector<int> arr;
		for (int i = 1; i < tmp; i++) {
			if (tmp%i == 0) {
				sum += i;
				arr.push_back(i);
			}
		}
		if (sum == tmp) {
			printf("%d = ", tmp);
			for (int i = 0; i < arr.size(); i++) {
				printf("%d",arr[i]);
				if (i != arr.size() - 1) {
					printf(" + ");
				}
				
			}
			printf("\n");
		}
		else {
			printf("%d is NOT perfect.\n", tmp);
		}
	}
}