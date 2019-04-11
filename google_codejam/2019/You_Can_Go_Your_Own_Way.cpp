#include<iostream>
#include<string>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		int k;
		scanf("%d", &k);
		std::string tmp;
		std::cin >> tmp;
		printf("Case #%d: ", i + 1);
		for (int j = 0; j<tmp.size(); j++) {
			printf("%c", tmp[j] == 'E' ? 'S' : 'E');
		}
		printf("\n");
	}
}