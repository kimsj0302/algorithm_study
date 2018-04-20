#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
int answer = 0;
void insert(int num, int *deep, int store[]) {
	static int max_deep=0;
	if (*deep > max_deep)
		max_deep = *deep;
	if (store[*deep + 1] == 0) {
		store[*deep] += num;
	}
	else {
		store[*deep] += num*store[*deep + 1];
		store[*deep + 1] = 0;
	}
	if (*deep == 1) {
		answer += store[1];
		for (int i = 0; i <= max_deep; i++) {
			store[i] = 0;
		}
		return;
	}
	

	//for (int i = 0; i <= 15; i++) {
	//	printf("%d",store[i]);
	//}
	//printf("\n");
}
int main() {
	int deep=0;
	char arr[31];
	int store[30] = { 0, };
	
	stack<int> _stack;
	scanf("%s", arr);
	int i;
	for (i = 0; arr[i]; i++) {
		//printf("arr[i]=%c\n", arr[i]);
		if (arr[i] == '(' || arr[i] == '[') {
			_stack.push(arr[i]);
			deep++;
			//printf("deep=%d, i=%d", deep, i);
		}
		else if (arr[i] == ')') {
			//printf("%c\n", _stack.top());
			if (_stack.empty()||_stack.top() != '(') {
				printf("0");
				return 0;
			}
			else{
				_stack.pop();
				insert(2,&deep,store );
			}
			deep--;
		}
		else if (arr[i] == ']') {
			//printf("%c\n", _stack.top());
			if (_stack.empty() || _stack.top() != '[') {
				printf("0");
				return 0;
			}
			else {
				_stack.pop();
				insert(3, &deep, store);
			}
			deep--;
		}
	}
	printf("%d", answer);
}
