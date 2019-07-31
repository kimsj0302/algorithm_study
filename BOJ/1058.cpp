#include<iostream>
#include<queue>
using namespace std;

int main(){
    int arr[50][50];
    int n;
    cin >>n;
    for(int i=0;i<n;i++){
        string t;
        cin >>t;
        for(int j=0;j<n;j++){
            if(t[j]=='Y') arr[i][j]=1;
            else arr[i][j]=0;
        }
    }
    int m=0;
    for(int i=0;i<n;i++){
        queue<pair<int,int> > que;
        que.push(make_pair(i,0));
        int visit[51]={0,};
        int sum=0;
        while(!que.empty()){
            int now=que.front().first;
            int order = que.front().second;
            que.pop();
            if(order==2)
                continue;
            for(int j=0;j<n;j++){
                if(i!=j && arr[now][j] && visit[j]==0){
                    sum++;

                    visit[j]=1;
                    que.push(make_pair(j,order+1));
                }
            }
        }
        m=max(m,sum);

    }
    cout << m <<endl;
}
