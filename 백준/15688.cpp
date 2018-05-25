#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> arr;
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        int tmp;
        scanf("%d",&tmp);
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<num;i++){
        printf("%d\n",arr[i]);
    }
}