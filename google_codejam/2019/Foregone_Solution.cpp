#include<iostream>
#include<string>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		std::string a;
		int b;
		std::cin >> a;
		b = 0;
		int tmp = 1;
		for (int j = 0; j < a.size(); j++) {
			b *= 10;
			if (a[j] == '4') {
				a[j] = '2';
				b += 2;
			}
		}
		printf("Case #%d: ", i + 1);
		std::cout << a;
		printf(" %d\n", b);
	}
}