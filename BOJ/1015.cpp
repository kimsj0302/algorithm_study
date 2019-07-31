#include<iostream>
using namespace std;

int main(){
    int arr[51]={0,};
    int result[51]={0,};
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int now=0;
    for(int j=0;j<1001;j++){
        for(int i=0;i<n;i++){
            if(arr[i]==j){
                result[i]=now++;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",result[i]);
    }
}
