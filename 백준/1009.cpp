#include<iostream>

int cal(int a,int b){
    if(b==1)
        return a;
    if(b==0)
        return 1;
    int half=cal(a,b/2);
    if(b%2==1)
        return (a*half*half)%10;
    else
        return (half*half)%10;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        int result=cal(a,b);
        if(result==0)
            printf("10\n");
        else
            printf("%d\n",result);
    }
}
