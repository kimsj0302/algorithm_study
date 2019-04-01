#include<iostream>
#include<map>
#include<string>
using namespace std;


int arr[100001];
int sizen[100001];
int n, m;
int find(int x) {
	if (arr[x] == x) {
		return x;
	}
	else {
		return arr[x] = find(arr[x]);
	}

}

void Union(int x, int y) {
	int a = find(x);
	int b = find(y);
	arr[b] = a;
	if (a != b) {
		sizen[a] += sizen[b];
		sizen[b] = sizen[a];
	}
}

int main() {
	scanf("%d", &n);
	cin.tie(0);
	for (int i = 0; i<n; i++) {
		scanf("%d", &m);
		int numbering = 1;
		map<string, int> ma;
		for (int i = 0; i<m; i++) {
			string a, b;
			cin >> a >> b;
			if (ma[a] == 0) {
				ma[a] = numbering;
				arr[numbering] = numbering;
				sizen[numbering] = 1;
				numbering++;
			}
			if (ma[b] == 0) {
				ma[b] = numbering;
				arr[numbering] = numbering;
				sizen[numbering] = 1;
				numbering++;
			}
			Union(ma[a], ma[b]);
			printf("%d\n", sizen[find(ma[a])]);
		}
	}
}
