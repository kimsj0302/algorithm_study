#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define PII pair<long long, long long>

const int N=1000000;

long long n;
int a,b,c;
long long dp[N+5];


struct line{  // y = a*x + b
    long long a,b;
};

struct convexhull_trick{
    int s=0,e=0;
    int idx[N+5];
    line deq[N+5];
    double cross(int a, int b) {
        return 1.0 * (deq[a].b - deq[b].b) / (deq[b].a - deq[a].a);
    }
    void insert(line v,int line_idx){
        deq[e] = v;
        idx[e] = line_idx;
        while(s+1<e && cross(e - 2, e - 1) > cross(e - 1, e)){
            deq[e-1] = deq[e];
            idx[e-1] = idx[e];
            e--;
        }
        e++;
    }
    PII query(int x){  // query가 증가수열일 경우
        while(s+1<e && deq[s+1].b - deq[s].b >= x * (deq[s].a - deq[s+1].a))
            s++;
        return PII(deq[s].a*x+deq[s].b,idx[s]);
    }
    PII query2(long long x){ // 일반 query
        int l = 0, r = e - 1;
        while (l != r) {
            int m = (l + r) / 2;
            if (cross(m, m + 1) <= x) l = m + 1;
            else r = m;
        }
        //printf("--%lld %lld\n",deq[l].a,deq[l].b);
        return PII(deq[l].a*x+deq[l].b,idx[l]);
    }
    void clear(){s = e = 0;}
}cht;


int main(){
  scanf("%lld",&n);
  vector<pair<long long,long long> > tmp;
  for(int i=0;i<n;i++){
    int W,H;
    scanf("%d%d",&W,&H);
    tmp.push_back(make_pair(W,H));
  }
  sort(tmp.begin(),tmp.end());
  vector<pair<long long ,long long> > arr;
  arr.push_back(tmp[0]);
  for(int i=1;i<n;i++){
	 while(!arr.empty() && arr.back().second <= tmp[i].second)
	 	arr.pop_back();
    arr.push_back(tmp[i]);
  }

  arr.push_back(make_pair(0,0));
    cht.clear();
    line ins;
    ins.a = arr[0].second;
    ins.b = 0;
    cht.insert(ins,0);
    for(int i=0; i<arr.size(); i++){
		dp[i] = cht.query2(arr[i].first).first;
        ins.a = arr[i+1].second;
        ins.b = dp[i];
        //printf("%lld %d %lld %lld\n",dp[i],i,ins.a,ins.b);
        cht.insert(ins,i+1);
    }
      printf("%lld\n",dp[arr.size()-2]);
    return 0;


}
