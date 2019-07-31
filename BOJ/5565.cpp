#include<stdio.h>
int main(){
    int answer;
    int num;
    scanf("%d",&answer);
    for(int i=0;i<9;i++){
        scanf("%d",&num);
        answer-=num;
    }
    printf("%d",answer);
}