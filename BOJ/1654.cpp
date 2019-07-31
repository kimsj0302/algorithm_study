#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> arr;
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        arr.push_back(tmp);
    }
    long long int st=0,nd=2147483647;
    long long int max=0;
    while(st!=nd){
        long long int sum=0;
        long long int mid=(st+nd)/2;
        for(int i=0;i<n;i++){
            sum+=arr[i]/mid;
        }
        if(sum<m)
            nd=mid;
        else
            st=mid+1;
        if(sum >= m && max < mid)
            max = mid;
    }
    long long int sum=0;
    long long int mid=(st+nd)/2;
    for(int i=0;i<n;i++){
        sum+=arr[i]/mid;
    }
    if(sum >= m && max < mid)
        max = mid;
    printf("%lld\n",max);

}
