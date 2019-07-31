#include<iostream>
#include<string>
using namespace std;

int main(){
    string st;
    cin >>st;
    bool ans=false;
    for(int d=-9;d<=9;d++){
        for(int i=1;i<st.size();i++){
            if(i==st.size()-1 && st[i-1]+d==st[i]) ans=true;
            if(st[i-1]+d!=st[i]) break;
        }
    }
    cout << ((ans||st.size()==1)?"◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!":"흥칫뿡!! <(￣ ﹌ ￣)>")<<endl;
}
