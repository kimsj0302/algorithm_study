#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr;
    while(n--){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    int answer=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==1) continue;
        if(arr[i]==2){
            answer++;
            continue;
        }
        int prime=1;
        for(int j=2;j<arr[i];j++){
            if(arr[i]%j==0)
                prime=0;
        }
        answer+=prime;
    }
    cout << answer;
}
