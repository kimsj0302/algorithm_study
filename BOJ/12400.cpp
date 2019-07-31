#include<iostream>
#include<vector>
#include<string>
using namespace std;
char arr[27]={' ','y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q' };

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 1; i <= n; i++) {
		char a[101];
		cin.getline(a,101);
		printf("Case #%d: ", i);
		for (int j = 0; a[j]!=NULL; j++) {
			if ('a'<=a[j]&&a[j]<='z')
				printf("%c", arr[a[j] - 'a' + 1]);
			else {
				printf("%c", a[j]);
			}
		}
		printf("\n");
	}
}