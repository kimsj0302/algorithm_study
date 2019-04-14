#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n,m;
	scanf("%d %d", &n,&m);
	vector<int> arr(n);
	int size = n;
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}
	int sum = 0;
	for (int i = 0; i < m; i++) {
		int target;
		scanf("%d", &target);
		int loctarget=-1;
		for (int j = 0; j < arr.size(); j++)
			if (arr[j]== target)
				loctarget = j;
		if (loctarget == -1)
			break;
		if ((size - loctarget) % size < (size + loctarget) % size) {
			for (int j = 0; j < (size - loctarget) % size; j++) {
				arr.insert(arr.begin(), *(arr.end()-1));
				arr.pop_back();
				sum++;
			}
		}
		else {
			for (int j = 0; j < (size  + loctarget) % size; j++) {
				arr.push_back(arr[0]);
				arr.erase(arr.begin());
				sum++;
			}
		}
		size--;
		arr.erase(arr.begin());
	}
	printf("%d\n", sum);
}