#include<iostream>
#include<vector>
using namespace std;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	vector<int> arr;
	int size=1;
	int result = 0;
	for (int i = 0; i < a; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp);
		size*=2;
	}
	for(int i=1;i<size;i++){
		int tmp=i;
		int sum=0;
		for(int j=0;j<a;j++){
			sum+=(tmp%2)*arr[j];
			tmp/=2;
		}
		if(sum==b)
			result++;
	}
	printf("%d", result);
}
