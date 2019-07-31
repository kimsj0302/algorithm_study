#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 2010
using namespace std;
int arr[MAX][MAX];
int rd[MAX][MAX];
int ld[MAX][MAX];

int level[MAX];
vector<int> graph[MAX];
int c[MAX][MAX], f[MAX][MAX];
int work[MAX];
int S, E;
bool bfs() {
	for (int i = 0; i < MAX; i++) level[i] = -1;
	level[S] = 0;
	queue<int> que;
	que.push(S);
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			if (level[next] == -1 && c[now][next] - f[now][next] > 0) {
				level[next] = level[now] + 1;
				que.push(next);
			}
		}
	}
	return level[E] != -1;
}

int dfs(int now, int dest, int flow) {
	if (now == dest) return flow;
	for (int& i = work[now]; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (level[next] == level[now] + 1 && c[now][next] - f[now][next] > 0) {
			int re = dfs(next, dest, min(c[now][next] - f[now][next], flow));
			if (re > 0) {
				f[now][next] += re;
				f[next][now] -= re;
				return re;
			}
		}
	}
	return 0;
}


int main() {
	int n;
	cin >>n;
	int num;
	cin >> num;
	for(int i=0;i<num;i++){
		int a,b;
		cin >>a>>b;
		arr[a-1][b-1]=1;
	}
	S=0;
	E=MAX-1;
	int rdnum=1;
	bool cons=true;
	for(int i=n-1;i>=0;i--){
		int x=i,y=0;
		while(x<n && y<n){
			if(!arr[x][y]){
				rd[x][y]=rdnum;
				cons=true;
			}
			else{
				if(cons){
					rdnum++;
				}
				cons=false;
			}
			x++;
			y++;
		}
		rdnum++;
		cons=false;
	}
	for(int i=1;i<n;i++){
		int x=0,y=i;
		while(x<n && y<n){
			if(!arr[x][y]){
				rd[x][y]=rdnum;
				cons=true;
			}
			else{
				if(cons){
					rdnum++;
				}
				cons=false;
			}
			x++;
			y++;
		}
		rdnum++;
	}
	int ldnum=rdnum+1;
	cons=false;
	for(int i=0;i<n;i++){
		int x=0,y=i;
		while(x<n && y<n){
			if(!arr[x][y]){
				ld[x][y]=ldnum;
				cons=true;
			}
			else{
				if(cons){
					ldnum++;
				}
				cons=false;
			}
			x++;
			y--;
		}
		ldnum++;
		cons=false;
	}
	for(int i=1;i<n;i++){
		int x=i,y=n-1;
		while(x<n && y<n){
			if(!arr[x][y]){
				ld[x][y]=ldnum;
				cons=true;
			}
			else{
				if(cons){
					ldnum++;
				}
				cons=false;
			}
			x++;
			y--;
		}
		ldnum++;
	}


	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!arr[i][j]){
				c[S][rd[i][j]]=1;
				graph[S].push_back(rd[i][j]);
				graph[rd[i][j]].push_back(S);

				c[rd[i][j]][ld[i][j]]=1;
				graph[ld[i][j]].push_back(rd[i][j]);
				graph[rd[i][j]].push_back(ld[i][j]);

				c[ld[i][j]][E]=1;
				graph[ld[i][j]].push_back(E);
				graph[E].push_back(ld[i][j]);

			}
		}
	}

	int ans = 0;
	while (bfs()) {
		for (int i = 0; i < MAX; i++) work[i] = 0;
		while (1) {
			int flow = dfs(S, E, 10000);
			if (!flow) break;
			ans += flow;
		}
	}
	cout << ans << endl;
}
