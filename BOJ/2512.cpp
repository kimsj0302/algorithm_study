#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<int> arr;
    long long int presum=0;
    int prem=0;
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        arr.push_back(tmp);
        presum+=tmp;
        if(prem<tmp)
            prem=tmp;
    }

    int m;
    scanf("%d",&m);
    long long int st=0,nd=1000000000;
    long long int max=0;
    while(st!=nd){
        long long int mid=(st+nd)/2;
        long long int sum=0;
        for(int i=0;i<n;i++){
            sum += arr[i]>mid ? mid : arr[i];
        }
        if(sum<=m){
            st=mid+1;
            if(mid>max)
                max=mid;
        }
        else
            nd=mid;

    }

    long long int mid=(st+nd)/2;
    long long int sum=0;
    for(int i=0;i<n;i++){
        sum += arr[i]>mid ? mid : arr[i];
    }
    if(sum<=m){
        st=mid+1;
        if(mid>max)
            max=mid;
    }
    else
        nd=mid;

    if(presum<=m){
        printf("%d\n",prem);
        return 0;
    }
    else
        printf("%lld\n",max);
}
