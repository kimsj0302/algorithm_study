#include<iostream>
#include<string>
#include<vector>
using namespace std;

int cost[4][4]={{0,1,2,1},{1,0,1,2},{2,1,0,1},{1,2,1,0}};

int main(){
	int size;
	cin >> size;
	size -= 2;
	vector<int> road;
	for(int i=0;i<size;i++){
		string tmp;
		cin >> tmp;
		if(tmp=="0111")
			road.push_back(0);
		if(tmp=="1011")
			road.push_back(1);
		if(tmp=="1101")
			road.push_back(2);
		if(tmp=="1110")
			road.push_back(3);
	}
	int min=size*2000;
	for(int i=0;i<4;i++){
		int sum=0;
		for(int j=0;j<road.size();j++){
			sum+=cost[road[j]][i];
		}
		if(sum<min)
			min=sum;
	}
	cout << min+4+size;
}