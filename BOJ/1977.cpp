#include<iostream>

using namespace std;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int sum=0;
    int min=-1;
    for(int i=1;i<=100;i++){
        if(i*i>=n && i*i<=m){
            if(min==-1)
                min=i*i;
            sum+=i*i;
        }
    }
    if(min==-1)
        printf("-1\n");
    else
        printf("%d\n%d\n",sum,min);
}
