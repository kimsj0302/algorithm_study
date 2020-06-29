#include<stdio.h>

int arr[26];
char st[101];
int main() {
	scanf("%s", st);
	for (int i = 0; i < 26; i++) {
		arr[i] = -1;
	}
	for (int i = 0; st[i]; i++) {
		if (arr[st[i] - 'a'] == -1) {
			arr[st[i] - 'a'] = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", arr[i]);
	}
}