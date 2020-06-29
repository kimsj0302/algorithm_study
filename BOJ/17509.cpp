#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<pair<int,int> > vec;
    for(int i=0;i<11;i++){
        int a,b;
        cin >> a>>b;
        vec.push_back(make_pair(a,b));
    }
    sort(vec.begin(),vec.end());
    int time=0;
    int ans=0;
    for(int i=0;i<11;i++){
        time+=vec[i].first;
        ans+=time+20*vec[i].second;
    }
    cout << ans << endl;
}
