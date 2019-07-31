#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int arr[10];
int main(){
    string room;
    cin >> room;
    for(int i=0;i<room.size();i++){
        if(room[i]=='9') arr[6]++;
        else arr[room[i]-'0']++;
    }
    int m=0;
    for(int i=0;i<9;i++){
        if(i==6)m=max(m,(arr[i]+1)/2);
        else m=max(m,arr[i]);
    }
    cout << m;
}
