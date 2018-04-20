#include<iostream>
using namespace std;

int arr[1000001]={0,0,1,1,0,};
int D(int n){
	if(arr[n]!=0 || n==1)
		return arr[n];
	int renum=D(n-1);
	if(n%3==0)
		renum=min(renum,D(n/3));
	if(n%2==0)
		renum=min(renum,D(n/2));
	arr[n]=renum+1;
	return arr[n];
	
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d",D(n));
}