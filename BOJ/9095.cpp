#include<iostream>

int arr[20]={0,1,2,4,};
int K(int n){
	if(n<1)
		return 0;
	if(n==1 || n==2 || n==3 || arr[n]!=0)
		return arr[n];
	return K(n-1)+K(n-2)+K(n-3);
}
int main(){
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		int tmp;
		scanf("%d",&tmp);
		printf("%d\n",K(tmp));
	}
}