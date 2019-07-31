#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        vector<pair<int,int> > arr;
        for(int j=0;j<num;j++){
            int test1,test2;
            scanf("%d %d",&test1,&test2);
            arr.push_back(make_pair(test1,test2));
        }
        sort(arr.begin(),arr.end());
        vector<int> rank;
        int min;
        for(int j=0;j<arr.size();j++){
            if(rank.empty()){
                rank.push_back(arr[j].second);
                min=arr[j].second;
            }
            else{
                if(min>arr[j].second){
                    rank.push_back(arr[j].second);
                    min=arr[j].second;
                }

            }
        }
        printf("%d\n",int(rank.size()));
    }

}
