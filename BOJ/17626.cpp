#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dp[50001];
int main(){
    vector<int> first,second;
    for(int i=0;i<50001;i++){
        dp[i]=4;
    }
    for(int i=1;i*i<=50000;i++){
        dp[i*i]=1;
        first.push_back(i*i);
    }
    for(int i=0;i<first.size();i++){
        for(int j=0;j<first.size();j++){
            int s = first[i]+first[j];
            if(s>50000) continue;
            dp[s]=min(dp[s],2);
            second.push_back(s);
        }
    }
    for(int i=0;i<first.size();i++){
        for(int j=0;j<second.size();j++){
            int t = first[i]+second[j];
            if(t>50000) continue;
            dp[t]=min(dp[t],3);
        }
    }
    int num;
    cin>>num;
    cout<<dp[num]<<endl;


}