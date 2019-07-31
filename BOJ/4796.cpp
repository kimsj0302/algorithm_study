#include<iostream>

using namespace std;
int main(){
	int L,P,V,ans,case_num=1;
	while(1){
		ans=0;
		scanf("%d %d %d",&L,&P,&V);
		if(L==0 && P==0 && V==0)
			break;
		ans=(V/P)*L;
		if(V%P>= L)
			ans+=L;
		else
			ans+=V%P;
		printf("Case %d: %d\n",case_num++,ans);
	}
}