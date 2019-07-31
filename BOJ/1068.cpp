#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n;
    cin>> n;
    vector<vector<int> > arr(51);
    int st;
    for(int i=0;i<n;i++){
        int tmp;
        cin >>tmp;
        if(tmp==-1){
            st=i;
        }
        else{
            arr[tmp].push_back(i);
        }
    }
    int rm;
    cin >>rm;
    if(rm==st){
        cout << "0\n";
        return 0;
    }
    queue<int> que;
    que.push(st);
    int answer=0;
    while(!que.empty()){
        int tmp=que.front();
        que.pop();
        int vi=0;
        for(int i=0;i<arr[tmp].size();i++){
            if(arr[tmp][i]!=rm){
                vi++;
                que.push(arr[tmp][i]);
            }
        }
        if(vi==0){
            answer++;
        }
    }
    cout << answer <<endl;
}
