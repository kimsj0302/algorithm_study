#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct seg {
	int l;
	int r;
	int index;
	bool operator<(const seg& rhs) const { return this->l < rhs.l; }
};
int main() {
	int num;
	scanf("%d", &num);
	vector<seg > arr;
	for (int i = 0; i < num; i++) {
		int a,b;
		scanf("%d %d", &a,&b);
		seg tmp = { a,b,i + 1 };
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	int max_r = arr[0].r, max_l=arr[0].l,max_ind=arr[0].index;
	for (int i = 0; i < arr.size(); i++) {
		if (max_r >= arr[i].r && max_l <= arr[i].l && max_ind!=arr[i].index) {
			printf("%d %d\n", arr[i].index,max_ind );
			return 0;
		}
		else {
			max_r = arr[i].r;
			max_l = arr[i].l;
			max_ind = arr[i].index;
		}

	}
	printf("-1 -1\n");
}