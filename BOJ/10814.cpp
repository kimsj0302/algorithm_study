#include <algorithm>
#include <iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	int N;
	vector <pair<int,pair<int,string>> > a;
	int age;
	string asd;
	scanf("%d", &N);
	for (int i = 0; i < N;i++) {
		scanf("%d", &age);
		cin >> asd;
		a.push_back(make_pair(age, make_pair(i,asd)));

	}
	sort(a.begin(), a.end());
	for (int i = 0; i < N; i++) {
		printf("%d ", a[i].first);
		cout << a[i].second.second;
		printf("\n");
	}
}