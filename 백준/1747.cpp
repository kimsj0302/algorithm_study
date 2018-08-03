#include<iostream>
#include<vector>
#define SIZE 1000010
using namespace std;
bool is_right[SIZE];

int answer[SIZE];
bool is_pel(int n) {
	vector<int> tmp;
	while (n > 0) {
		tmp.push_back(n % 10);
		n =n/ 10;
	}
	int totalsize = tmp.size();
	if (totalsize % 2 == 0) {
		for (int i = 0; i <= totalsize / 2 - 1; i++) {
			if (tmp[i] != tmp[totalsize - i - 1])
				return false;
		}
	}
	else {
		for (int i = 0; i <= totalsize / 2; i++) {
			if (tmp[i] != tmp[totalsize - i - 1])
				return false;
		}
	}
	return true;
}
int main() {
	for (int i = 0; i < SIZE; i++) {
		is_right[i] = true;
	}
	is_right[1] = false;
	is_right[2] = true;
	for (int i = 2; i < SIZE; i++) {
		if (is_right[i] == false)
			continue;
		for (int j = i + i; j < SIZE; j+=i) {
			is_right[j] = false;
		}
		if (!is_pel(i)) {
			is_right[i] = false;
			
		}
	}
	for (int i = SIZE - 1; i >= 1; i--) {
		if (i > 98689) {
			answer[i] = 1003001;
			continue;
		}

		if (is_right[i]) {
			answer[i] = i;
		}
		else {
			answer[i] = answer[i + 1];
		}
	}
	int n;
	scanf("%d", &n);
	printf("%d\n", answer[n]);
}