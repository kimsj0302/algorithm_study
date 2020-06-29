#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
	int n;
	cin >> n;
	int now = 1;
	string result = "";
	stack<int> sta;
	for (int i = 0; i < n; i++) {
		int target;
		cin >> target;
		if (!sta.empty() && sta.top() == target) {
			sta.pop();
			result+= "-\n";
		}
		else if(now<=target){
			while (now <= target) {
				sta.push(now++);
				result += "+\n";
			}
			sta.pop();
			result += "-\n";
		}
		else {
			result = "NO";
			break;
		}
	}
	cout << result << endl;
}