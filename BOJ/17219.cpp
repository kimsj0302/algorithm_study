#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int main(){
    map<string,string> ma;
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >>n>>m;
    while(n--){
        string a,b;
        cin >>a>>b;
        ma[a]=b;
    }
    while(m--){
        string ans;
        cin >> ans;
        cout << ma[ans]<<"\n";
    }



}