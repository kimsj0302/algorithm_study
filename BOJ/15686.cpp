#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int map[51][51];
int ch_dist[15][101] = {
    0,
};
int n, m;
int abs(int n){
    if(n>0) return n;
    return -1 * n;
}
int cal_m(vector<int> &selected){
    int min_dist[101]={0,};
    for(int i=0;i<selected.size();i++){
        if(!selected[i]) continue;
        for(int j=0;j<101;j++){
            if (min_dist[j] == 0)
            {
                min_dist[j]=ch_dist[i][j];
            }
            else
            {
                min_dist[j]=min(min_dist[j],ch_dist[i][j]);
            }
        }
    }
    int sum=0;
    for(int i=0;i<101;i++){
        sum+=min_dist[i];
    }
    return sum;

}
int cal(vector<int> &visited,int counter,int th){
    if(counter == m) return cal_m(visited);
    int mi = 1000000000;
    for(int i=th;i<visited.size();i++){
        if(visited[i]) continue;
        visited[i]=1;
        mi = min(mi,cal(visited,counter+1,i+1));
        visited[i]=0;
    }
    return mi;

}
void cal_chdist(int ind,int lx,int ly,int n){
    int count =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]==1){
                ch_dist[ind][count++] = abs(lx - i) + abs(ly - j);
            }
        }
    }
}
int main(){
    cin >> n >>m;
    for(int i=0;i < n;i++){
        for(int j=0;j < n;j++){
            cin >> map[i][j];
        }
    }
    int index=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]==2){
                cal_chdist(index,i,j,n);
                index++;
            }
        }
    }
    vector<int> visited(index,0);
    cout << cal(visited,0,0)<<endl;

}