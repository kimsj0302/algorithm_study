#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<fstream>

using namespace std;


int main() {
	int ro, cl;
	scanf("%d %d", &ro, &cl);
	if (ro == 1)
		printf("1\n");
	else if (ro == 2) {
		if (cl < 3)
			printf("1\n");
		else if (cl < 5)
			printf("2\n");
		else if (cl < 7)
			printf("3\n");
		else
			printf("4\n");
	}
	else {
		int answer = cl;
		if (answer >= 6)
			answer -= 2;
		else if (answer == 5)
			answer--;
		printf("%d\n", answer);
	}

}