#include<iostream>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int sum=0;
        int stx,sty,ndx,ndy;
        scanf("%d %d %d %d",&stx,&sty,&ndx,&ndy);
        int m;
        scanf("%d",&m);
        for(int j=0;j<m;j++){
            int x,y,r;
            scanf("%d %d %d",&x,&y,&r);
            if((stx-x)*(stx-x) + (sty-y)*(sty-y) < r*r && (ndx-x)*(ndx-x) + (ndy-y)*(ndy-y) < r*r)
                continue;
            if((stx-x)*(stx-x) + (sty-y)*(sty-y) < r*r)
                sum++;
            if((ndx-x)*(ndx-x) + (ndy-y)*(ndy-y) < r*r)
                sum++;
        }
        printf("%d\n",sum);
    }
}
