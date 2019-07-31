#include<iostream>
int main(){
    int n,num;
    scanf("%d %d",&n,&num);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        a<num?printf("%d ",a):a=1;
    }
}
