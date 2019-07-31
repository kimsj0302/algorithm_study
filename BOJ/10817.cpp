#include <algorithm>
#include <iostream>
#include<string>

using namespace std;

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d", a+b+c-max(a, max(b, c))- min(a, min(b, c)));
}

