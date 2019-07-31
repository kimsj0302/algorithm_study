#include <algorithm>
#include <iostream>
#include<map>
#include<string>

using namespace std;

int main() {
	map <string, int> m;
	int N, M;
	scanf("%d", &N);
	m["black"] = 0;
	m["brown"] = 1;
	m["red"] = 2;
	m["orange"] = 3;
	m["yellow"] = 4;
	m["green"] = 5;
	m["blue"] = 6;
	m["violet"] = 7;
	m["grey"] = 8;
	m["white"] = 9;
	string st1, st2, st3;
	getline(cin,st1);
	//printf("%d", m[st1]);
	getline(cin, st2);
	getline(cin, st3);
	//printf("%d %d %d", m[st1], m[st2], m[st3]);
	long long a = (m[st1] * 10 + m[st2])*pow(10, m[st3]);
	printf("%lld",  a);
}

