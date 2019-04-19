#include<iostream>

using namespace std;


 int pow(int a,int b){
     if(b==0)
        return 1;
     int r=1;
     for(r=1;b;r*=a,b--);
     return r;
 }

 int banolim(int a,int length){

     bool isup=false;
     if(a%(pow(10,length-1))/pow(10,length-2)>=5){
         isup=true;
     }
     a = a/pow(10,length-1)*pow(10,length-1);
     return a+(isup?pow(10,length-1):0);
 }
int main(){
    int num;
    scanf("%d",&num);
    int tmp=num;
    int length=0;
    for(length=0;tmp;tmp/=10 , length++);
    bool isup=false;
    for(int i=2;i<=length;i++){
        num=banolim(num,i);
    }
    printf("%d\n",num);

}
