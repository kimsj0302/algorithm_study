#include<iostream>

using namespace std;

int arr[1000000];
int n,m;
int find(int x){
	if(arr[x]==x){
		return x;
	}
	else{
		return arr[x]=find(arr[x]);
	}

}

void Union(int x,int y){
	int a=find(x);
	int b=find(y);
	arr[a]=b;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<=n;i++){
		arr[i]=i;
	}
	for(int i=0;i<m;i++){
		int com;
		scanf("%d",&com);
		if(com==0){
			int a,b;
			scanf("%d %d",&a,&b);
			Union(a,b);
		}
		else{
			int a,b;
			scanf("%d %d",&a,&b);
			if(find(a)==find(b))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}
