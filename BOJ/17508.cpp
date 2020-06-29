#include<iostream>
#include<string>

int arr[500][500];
using namespace std;

int main(){
    int n,m;
    cin >> n>> m;
    for(int i=0;i<n;i++){
        string tmp;
        cin >> tmp;
        for(int j=0;j<m;j++){
            arr[i][j]=tmp[j];
        }
    }
    int midn=n/2,midm=m/2;
    if(n%2==1 && m%2==1){
        if(arr[midn][midm]!='8'){
            cout << "-1"<<endl;
            return 0;
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(n%2==0){
                if(i>=midn){
                    cout << sum <<endl;
                    return 0;

                }
            }
            if(i>= midn && j>=midm){
                cout << sum <<endl;
                return 0;
            }
            if(arr[i][j]=='6'){
                if(arr[n-1-i][m-1-j]=='6'){
                    sum++;
                }
                else if(arr[n-1-i][m-1-j]=='9');
                else{
                    cout << "-1"<<endl;
                    return 0;
                }
            }
            if(arr[i][j]=='8'){
                if(arr[n-1-i][m-1-j]!='8'){
                    cout << "-1"<<endl;
                    return 0;
                }
            }
            if(arr[i][j]=='9'){
                if(arr[n-1-i][m-1-j]=='9'){
                    sum++;
                }
                else if(arr[n-1-i][m-1-j]=='6');
                else{
                    cout << "-1"<<endl;
                    return 0;
                }
            }
            if(arr[i][j]=='7'){
                if(arr[n-i-1][m-j-1]=='7'){
                    sum++;
                }
                else{
                    cout << "-1"<<endl;
                    return 0;
                }
            }
        }
    }
}
