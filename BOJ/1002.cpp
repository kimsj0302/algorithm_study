#include<iostream>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x1,x2,y1,y2,r1,r2;
        scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
        int d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        if(x1==x2 && y1==y2 && r1==r2)
            printf("-1\n");
        else if(d > (r1+r2)*(r1+r2))
            printf("0\n");
        else if((r1*r1>d || r2*r2>d) && (r1-r2)*(r1-r2) > d)
            printf("0\n");
        else if((r1*r1>d || r2*r2>d) && (r1-r2)*(r1-r2) == d)
            printf("1\n");
        else if(d == (r1+r2)*(r1+r2))
            printf("1\n");
        else
            printf("2\n");
    }
}
