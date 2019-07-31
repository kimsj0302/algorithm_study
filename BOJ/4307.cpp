#include<iostream>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int len,num;
        scanf("%d %d",&len,&num);
        int min=0,max=0;
        for(int j=0;j<num;j++){
            int tmp;
            scanf("%d",&tmp);
            if(min<(tmp<len-tmp?tmp:len-tmp))
                min = (tmp<len-tmp?tmp:len-tmp);
            if(max<(tmp>len-tmp?tmp:len-tmp))
                max = (tmp>len-tmp?tmp:len-tmp);
        }
        printf("%d %d\n",min,max);
    }
}
