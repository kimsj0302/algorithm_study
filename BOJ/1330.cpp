#include<iostream>

using namespace std;

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    if(a<b)
        printf("<");
    else if(a>b)
        printf(">");
    else
        printf("==");
}