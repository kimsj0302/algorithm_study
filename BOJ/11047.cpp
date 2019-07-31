#include<iostream>
#include<vector>
using namespace std;
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	vector<int> price;
	for(int i=0;i<a;i++){
		int tmp;
		scanf("%d",&tmp);
		price.push_back(tmp);
	}
	int answer=0;
	for(int i=price.size()-1;i>=0;i--){
		if(price[i]>b)
			continue;
		else{
			answer+=b/price[i];
			b=b%price[i];
		}
	}
	printf("%d",answer);
}