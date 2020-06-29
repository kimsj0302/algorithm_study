#include<iostream>
#include<algorithm>
using namespace std;
string A, B;
int C[10011]={0, };

int main() {
	cin >> A >> B;
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end()); 
	int i;
	for (i= 0; i < min(A.length(), B.length()); i++) {
		int sum = A[i] + B[i] - 2 * '0' + C[i];
		if (sum >= 10) {
			C[i + 1]++;
			sum -= 10;
		}
		C[i] = sum;
	}
	for (; i < max(A.length(), B.length()); i++) {
		int sum;
		if (i >= A.length()) sum = B[i] - '0'+C[i];
		else sum = A[i] - '0' + C[i];
		if (sum >= 10) {
			C[i + 1]++;
			sum -= 10;
		}
		C[i] = sum;
	}
	i--;
	if (C[i + 1] != 0) i++;
	for (; i >= 0; i--) {
		printf("%d", C[i]);
	}
}