#include<stdio.h>
#include<string.h>
int main(){
    char arr1[1000];
    char arr2[1000];
    scanf("%s",arr1);
    scanf("%s",arr2);
    if(strlen(arr1)>=strlen(arr2))
        printf("go");
    else
        printf("no");
}